
#include "P_Map16x16.h"
#include "numbers.h"
#include "levelSel.h"
#include "sky.h"

u16 *mapMemory;
int MapCols;
int MapRows;

// Declare the tiles emptyTile and fullTile as explained in the manual
u8 emptyTile[64] =
    {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0};

u8 fullTile[64] =
    {
        255, 255, 255, 255, 255, 255, 255, 255,
        255, 254, 254, 254, 254, 254, 254, 255,
        255, 254, 255, 255, 255, 255, 254, 255,
        255, 254, 255, 255, 255, 255, 254, 255,
        255, 254, 255, 255, 255, 255, 254, 255,
        255, 254, 255, 255, 255, 255, 254, 255,
        255, 254, 254, 254, 254, 254, 254, 255,
        255, 255, 255, 255, 255, 255, 255, 255};

void P_Map16x16_configureBG0_Sub()
{
    // Configure the Background
    BGCTRL_SUB[0] = BG_32x32 | BG_COLOR_16 | BG_MAP_BASE(24) | BG_TILE_BASE(4);
    // Copy tiles and palette
    dmaCopy(numbersTiles, BG_TILE_RAM_SUB(4), numbersTilesLen);
    dmaCopy(numbersPal, &BG_PALETTE_SUB[128], numbersPalLen);
    dmaCopy(numbersPal, &BG_PALETTE_SUB[144], numbersPalLen);
    BG_PALETTE_SUB[129] = ARGB16(1, 31, 0, 0);
    BG_PALETTE_SUB[145] = ARGB16(1, 0, 31, 0);

    // Set map to 0 (clean)
    memset(BG_MAP_RAM_SUB(24), 0, 32 * 32 * 2);
}

void P_Map16x16_configureBG2_Sub()
{
    // Configure BG 2 Sub. (Do not forget the BG_BMP_BASE configuration)
    BGCTRL_SUB[2] = BG_BMP_BASE(0) | BgSize_B8_256x256;

    // Affine Marix Transformation
    REG_BG2PA_SUB = 256;
    REG_BG2PC_SUB = 0;
    REG_BG2PB_SUB = 0;
    REG_BG2PD_SUB = 256;

    swiCopy(levelSelPal, BG_PALETTE_SUB, levelSelPalLen);
    swiCopy(levelSelBitmap, BG_GFX_SUB, levelSelBitmapLen);
}

void P_Map16x16_configureBG0()
{
    /*
     * GRAPHICS III
     *
     * This function is called in the initialization of the P_Map16x16 to
     * configure the Background 0 (on the top).
     *
     * This background is going to be used to draw the game field where
     * the blocks are falling.
     *
     * The function does not return anything and it does not have any input
     * arguments. Background 0 (BG0) should be configured in the tiled mode
     * as a 32x32 tile grid and using one general color palette of 256
     * components (256 colors). The pointer to the map 'mapMemory' must be
     * correctly assigned before returning from the function
     */

    // Configure BG 0 to represent the game field
    BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(25) | BG_TILE_BASE(4);

    // Copy the empty tile and the full tile to the corresponding RAM location
    // according to the chosen TILE_BASE. If dmaCopy is used, do not forget to
    // cast the destination pointer as a 'byte pointer'
    // Hint: Use the macro BG_TILE_RAM to get the destination address
    dmaCopy(emptyTile, (u8 *)BG_TILE_RAM(4), 64);
    dmaCopy(fullTile, (u8 *)BG_TILE_RAM(4) + 64, 64);

    // Assign components 254 and 255 as explained in the manual
    BG_PALETTE[254] = ARGB16(1, 0, 0, 0);
    BG_PALETTE[255] = ARGB16(1, 31, 15, 0);

    // Set the pointer mapMemory to the RAM location of the chosen MAP_BASE
    // Hint: use the macro BG_MAP_RAM
    mapMemory = (u16 *)BG_MAP_RAM(25);
}

void P_Map16x16_configureBG3()
{
    /*GRAPHICS III
     *
     * This function is called in the initialization of the P_Map16x16 to
     * configure the Background 3.
     *
     * This background is going to be used to background wall-paper.
     *
     * In exercise 2 the Background 3 (BG3) should be configure in rotoscale
     * mode with a 8 bits of pixel depth. Do not forget to copy the palette
     * correctly.
     *
     * In exercise 5 Background 3 (BG3) should be configured in the tiled mode
     * as a 32x32 tile grid and using one general color palette of 256
     * components (256 colors).
     */

    // Configure BG 3 for the background image as explained before
    BGCTRL[3] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(26) | BG_TILE_BASE(0);

    // Copy tiles, map and palette in the memory (use swicopy or memcpy)
    swiCopy(skyTiles, BG_TILE_RAM(0), skyTilesLen);
    swiCopy(skyMap, BG_MAP_RAM(26), skyMapLen);
    swiCopy(skyPal, BG_PALETTE, skyPalLen);
}

void P_Map16x16_Init(int cols, int rows)
{
    MapCols = cols;
    MapRows = rows;
    // Configure BG3 for background image
    P_Map16x16_configureBG3();
    // Configure BG0 for game
    P_Map16x16_configureBG0();
    // Configure Bottom background

    P_Map16x16_configureBG2_Sub();
    // Configure BG0 in the sub engine
    P_Map16x16_configureBG0_Sub();
}

void SetMap16x16To(int index16, bool full)
{
    // switch x and y
    int x = index16 % MapCols;
    int y = index16 / MapCols;
    // now inverse x
    y = -(y - MapRows + 1);
    index16 = x * MapRows + y;
#ifdef FB0
    u16 value = full ? RGB15(31, 0, 0) : RGB15(0, 0, 0);
    FillRectangle(MAIN, x * 16, x * 16 + 16, y * 16, y * 16 + 16, value);
#endif

#ifdef ROTOSCALE
    u16 value = full ? ARGB16(1, 31, 0, 0) : ARGB16(1, 0, 0, 0);
    FillRectangle(MAIN, x * 16, x * 16 + 16, y * 16, y * 16 + 16, value);
#endif

#ifdef TILES
    int value = full ? 1 : 0;
    // convert index16x16 to 32x32
    // also make it fall right->left rather than top->bottom
    //
    //   0  1  2  3     12  8  4  0
    //   4  5  6  7  => 13  9  5  1
    //   8  9 10 11  => 14 10  6  2
    //  12 13 14 15     15 11  7  3

    // 16x16->32*32 CONVERSION
    int index32;
    index32 = index16 * 2;
    index32 += (index16 / 16) * 32;
    mapMemory[index32] = value;
    mapMemory[index32 + 1] = value;
    mapMemory[index32 + 32] = value;
    mapMemory[index32 + 32 + 1] = value;
#endif
}

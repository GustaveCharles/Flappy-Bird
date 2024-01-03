
//{{BLOCK(sky)

//======================================================================
//
//	sky, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 686 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 43904 + 1536 = 45952
//
//	Time-stamp: 2024-01-03, 10:31:16
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SKY_H
#define GRIT_SKY_H

#define skyTilesLen 43904
extern const unsigned int skyTiles[10976];

#define skyMapLen 1536
extern const unsigned short skyMap[768];

#define skyPalLen 512
extern const unsigned short skyPal[256];

#endif // GRIT_SKY_H

//}}BLOCK(sky)

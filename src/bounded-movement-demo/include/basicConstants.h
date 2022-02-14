#ifndef __BASIC_CONSTANTS_H__
#define __BASIC_CONSTANTS_H__

// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------

#define TOTAL_PIXELS_X 240
#define TOTAL_PIXELS_Y 180

#define CENTER_PIXEL_X (TOTAL_PIXELS_X / 2) - 1
#define CENTER_PIXEL_Y (TOTAL_PIXELS_Y / 2) - 1

#define CENTER_TILE_X CENTER_PIXEL_X - 16
#define CENTER_TILE_Y CENTER_PIXEL_Y - 16

#define DIR_NEUTRAL 0

#define DIR_SOUTH -1
#define DIR_NORTH 1

#define DIR_EAST 1
#define DIR_WEST -1

#endif // __BASIC_CONSTANTS_H__

// EOF
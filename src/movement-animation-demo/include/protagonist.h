#ifndef __PROTAGONIST_H__
#define __PROTAGONIST_H__

#include <tonc.h>
// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------

#define PROTAGONIST_PALLET_BANK 0

#define PROTAGONIST_NEUTRAL_SOUTH_OBJ_BUFFER_POS 0
#define PROTAGONIST_NEUTRAL_SOUTH_TID PROTAGONIST_NEUTRAL_SOUTH_OBJ_BUFFER_POS * 8

#define PROTAGONIST_NEUTRAL_NORTH_OBJ_BUFFER_POS 16
#define PROTAGONIST_NEUTRAL_NORTH_TID PROTAGONIST_NEUTRAL_NORTH_OBJ_BUFFER_POS * 8

#define PROTAGONIST_NEUTRAL_EAST_OBJ_BUFFER_POS 32
#define PROTAGONIST_NEUTRAL_EAST_TID PROTAGONIST_NEUTRAL_EAST_OBJ_BUFFER_POS * 8

#define PROTAGONIST_NEUTRAL_WEST_OBJ_BUFFER_POS 48
#define PROTAGONIST_NEUTRAL_WEST_TID PROTAGONIST_NEUTRAL_WEST_OBJ_BUFFER_POS * 8

// --------------------------------------------------------------------
// TYPES
// --------------------------------------------------------------------

typedef struct Protagonist
{
  int position_x;
  int position_y;
  int velocity_x;
  int velocity_y;
  OBJ_ATTR *protagonistSpriteCurrent;

} Protagonist;

// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

void protagonist_init(Protagonist *protagonist);

void protagonist_update_facing(Protagonist *protagonist);

void protagonist_move(Protagonist *protagonist);

#endif // __PROTAGONIST_H__

// EOF
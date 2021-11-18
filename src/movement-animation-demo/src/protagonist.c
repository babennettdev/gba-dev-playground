#include <string.h>

#include <tonc.h>
#include "protagonist.h"

// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

// Initialize Protagonist (Assumes tiles have already been copied into memory).
void protagonist_init(Protagonist *protagonist)
{

  obj_set_attr(protagonist->protagonistSpriteCurrent,
               ATTR0_4BPP | ATTR0_SQUARE,                                                                          // Square, 4bpp sprite
               ATTR1_SIZE_32x32,                                                                                   // 32x32,
               ATTR2_PALBANK(PROTAGONIST_PALLET_BANK) | PROTAGONIST_NEUTRAL_SOUTH_OBJ_BUFFER_POS | ATTR2_PRIO(0)); // tile 0, priority 0
  obj_set_pos(protagonist->protagonistSpriteCurrent, protagonist->position_x, protagonist->position_y);
}

void protagonist_update_facing(Protagonist *protagonist)
{

  switch (protagonist->velocity_x)
  {
  case 1:
    switch (protagonist->velocity_y)
    {
    case 1:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_EAST_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    case -1:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_EAST_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    default:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_EAST_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    }
    break;

  case -1:
    switch (protagonist->velocity_y)
    {
    case 1:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_WEST_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    case -1:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_WEST_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    default:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_WEST_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    }
    break;

  default:
    switch (protagonist->velocity_y)
    {
    case 1:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_SOUTH_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;

    case -1:
      protagonist->sprite_facing = PROTAGONIST_NEUTRAL_NORTH_OBJ_BUFFER_POS + protagonist->animation_frame;
      break;
    default:
      protagonist->sprite_facing += protagonist->animation_frame;
      break;
    }
    break;
  }
}

void protagonist_move(Protagonist *protagonist)
{
  if (protagonist->velocity_x != 0 || protagonist->velocity_y != 0)
  {
    protagonist_update_facing(protagonist);
    protagonist->sprite_tick += 1;
    if (protagonist->sprite_tick > 7)
    {
      protagonist->sprite_tick = 0;
      protagonist_animate_movement(protagonist);
      //protagonist_update_facing(protagonist);
    }
  }
  else
    protagonist->sprite_tick = 0;

  protagonist->position_x += protagonist->velocity_x;
  protagonist->position_y += protagonist->velocity_y;
  protagonist->protagonistSpriteCurrent->attr2 = ATTR2_BUILD(protagonist->sprite_facing, PROTAGONIST_PALLET_BANK, 0);
  obj_set_pos(protagonist->protagonistSpriteCurrent, protagonist->position_x, protagonist->position_y);
}

void protagonist_animate_movement(Protagonist *protagonist)
{

  protagonist->animation_frame = protagonist->animation_frame < 3 * 16 ? protagonist->animation_frame + 1 * 16 : 0;
}
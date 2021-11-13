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

void protagonist_move(Protagonist *protagonist)
{
  protagonist->protagonistSpriteCurrent->attr2 = ATTR2_BUILD(PROTAGONIST_NEUTRAL_SOUTH_OBJ_BUFFER_POS, PROTAGONIST_PALLET_BANK, 0);

  obj_set_pos(protagonist->protagonistSpriteCurrent, protagonist->position_x, protagonist->position_y);
}
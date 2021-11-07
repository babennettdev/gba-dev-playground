#include <string.h>

#include <tonc.h>
#include "tower.h"

// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

// Create Tower (Assumes tiles have already been copied into memory).
void tower_init(OBJ_ATTR *towerBase, OBJ_ATTR *towerTurret, OBJ_AFFINE *obj_aff_buffer, int tower_starting_pos_x, int tower_starting_pos_y)
{

  obj_set_attr(towerBase,
               ATTR0_8BPP | ATTR0_SQUARE,       // Square, 8bpp sprite
               ATTR1_SIZE_16,                   // 16x16,
               TOWER_BASE_TID | ATTR2_PRIO(3)); // tile 0

  obj_set_pos(towerBase, tower_starting_pos_x, tower_starting_pos_y);

  obj_set_attr(towerTurret,
               ATTR0_8BPP | ATTR0_SQUARE | ATTR0_AFF, // Square, 8bpp affine sprite
               ATTR1_SIZE_16 | ATTR1_AFF_ID(0),       // 16x16,
               TOWER_TURRET_TID | ATTR2_PRIO(1));     // tile 1
  obj_set_pos(towerTurret, tower_starting_pos_x, tower_starting_pos_y);
  obj_aff_identity(&obj_aff_buffer[0]);
}
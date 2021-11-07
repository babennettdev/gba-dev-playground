#ifndef __TOWER_H__
#define __TOWER_H__

#include <tonc.h>
#include "robot.h"
// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------

#define TOWER_BASE_OBJ_BUFFER_POS 0
#define TOWER_BASE_TID TOWER_BASE_OBJ_BUFFER_POS * 8

#define TOWER_TURRET_OBJ_BUFFER_POS 1
#define TOWER_TURRET_TID TOWER_TURRET_OBJ_BUFFER_POS * 8

// --------------------------------------------------------------------
// TYPES
// --------------------------------------------------------------------

typedef struct Tower
{
  const int position_x;
  const int position_y;
  Robot *target;
} Tower;

// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

void tower_create();

void tower_init(OBJ_ATTR *towerBase, OBJ_ATTR *towerTurret, int tower_starting_pos_x, int tower_starting_pos_y);
void tower_run();
void tower_draw();

void calculate_target();
void damage_target();

#endif // __TOWER_H__

// EOF
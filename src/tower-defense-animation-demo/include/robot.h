#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <tonc.h>

// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------

#define ROBOT_OBJ_BUFFER_POS 2
#define ROBOT_TID ROBOT_OBJ_BUFFER_POS * 8

// --------------------------------------------------------------------
// TYPES
// --------------------------------------------------------------------

typedef struct Robot
{
  int position_x;
  int position_y;
} Robot;

// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

void robot_create();

void robot_init(OBJ_ATTR *robot, int robot_starting_pos_x, int robot_starting_pos_y);
void robot_run();
void robot_draw();

#endif // __ROBOT_H__

// EOF
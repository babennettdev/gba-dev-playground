#include <string.h>

#include <tonc.h>
#include "robot.h"

// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

// Create Robot (Assumes tiles have already been copied into memory).
void robot_init(OBJ_ATTR *robot, int robot_starting_pos_x, int robot_starting_pos_y)
{

  obj_set_attr(robot,
               ATTR0_8BPP | ATTR0_SQUARE,  // Square, 8bpp sprite
               ATTR1_SIZE_16,              // 16x16,
               ROBOT_TID | ATTR2_PRIO(2)); // tile 2

  obj_set_pos(robot, robot_starting_pos_x, robot_starting_pos_y);

}
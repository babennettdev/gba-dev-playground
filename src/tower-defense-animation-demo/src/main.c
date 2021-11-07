#include "basicConstants.h"
#include "first_draft_sprites.h"
#include "robot.h"
#include "tower.h"

#include <string.h>
#include <tonc.h>

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *)obj_buffer;

void obj_test()
{
  int turret_pos_x = CENTER_TILE_X, turret_pos_y = CENTER_TILE_Y;
  int robot_pos_x = 0, robot_pos_y = 0;

  OBJ_ATTR *towerBase = &obj_buffer[0];
  OBJ_ATTR *towerTurret = &obj_buffer[1];
  tower_init(towerBase, towerTurret, robot_pos_x, robot_pos_x);

  OBJ_ATTR *robot = &obj_buffer[ROBOT_OBJ_BUFFER_POS];
  robot_init(robot, robot_pos_x, robot_pos_x);
  oam_copy(oam_mem, obj_buffer, 4);
  while (1)
  {
    vid_vsync();
    key_poll();

    towerBase->attr2 = ATTR2_BUILD(TOWER_BASE_TID, 0, 3);
    towerTurret->attr2 = ATTR2_BUILD(TOWER_TURRET_TID, 0, 1);
    robot->attr2 = ATTR2_BUILD(ROBOT_TID, 0, 2);

    obj_set_pos(towerBase, turret_pos_x, turret_pos_y);
    obj_set_pos(towerTurret, turret_pos_x, turret_pos_y);
    obj_set_pos(robot, robot_pos_x, robot_pos_y);

    // move left/right
    robot_pos_x += 2 * key_tri_horz();

    // move up/down
    robot_pos_y += 2 * key_tri_vert();
    oam_copy(oam_mem, obj_buffer, 4);
  }
}

int main()
{
  memcpy(&tile_mem[4][0], first_draft_spritesTiles, first_draft_spritesTilesLen);
  memcpy(pal_obj_mem, first_draft_spritesPal, first_draft_spritesPalLen);

  oam_init(obj_buffer, 128);
  REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D;

  obj_test();

  while (1)
    ;

  return 0;
}
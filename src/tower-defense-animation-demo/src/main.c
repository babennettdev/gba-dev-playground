#include "first_draft_sprites.h"
#include <string.h>
#include <tonc.h>

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *)obj_buffer;

void obj_test()
{
  int x = 96, y = 32;
  u32 tid = 0; // tile id

  OBJ_ATTR *turretBase = &obj_buffer[0];
  obj_set_attr(turretBase,
               ATTR0_8BPP | ATTR0_SQUARE, // Square, 8bpp sprite
               ATTR1_SIZE_16,             // 16x16,
               tid | ATTR2_PRIO(3));      // tile 0

  obj_set_pos(turretBase, x, y);

  OBJ_ATTR *turretGun = &obj_buffer[1];
  obj_set_attr(turretGun,
               ATTR0_8BPP | ATTR0_SQUARE,  // Square, 8bpp sprite
               ATTR1_SIZE_16,              // 16x16,
               (tid + 8) | ATTR2_PRIO(1)); // tile 1
  obj_set_pos(turretGun, x, y);

  OBJ_ATTR *robot = &obj_buffer[2];
  obj_set_attr(robot,
               ATTR0_8BPP | ATTR0_SQUARE,   // Square, 8bpp sprite
               ATTR1_SIZE_16,               // 16x16,
               (tid + 16) | ATTR2_PRIO(2)); // tile 2

  obj_set_pos(robot, x + 32, y + 32);

  while (1)
  {
    vid_vsync();
    key_poll();

    turretBase->attr2 = ATTR2_BUILD(tid, 0, 3);
    turretGun->attr2 = ATTR2_BUILD(tid + 8, 0, 1);
    robot->attr2 = ATTR2_BUILD(tid + 16, 0, 2);

    obj_set_pos(turretBase, x, y);
    obj_set_pos(turretGun, x, y);
    obj_set_pos(robot, x + 32, y + 32);
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
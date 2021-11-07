#include "basicConstants.h"
#include "first_draft_sprites.h"
#include "robot.h"
#include "tower.h"

#include <string.h>
#include <tonc.h>

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *)obj_buffer;

// affine transformation constants and variables
enum eAffState
{
  AFF_NULL = 0,
  AFF_ROTATE,
  AFF_COUNT
};

// 'speeds' of transformations
const int aff_diffs[AFF_COUNT] = {0, 128};

// keys for transformation direction
const int aff_keys[AFF_COUNT] =
    {0, KEY_L};
int aff_state = AFF_NULL;
int aff_value = 0;

// === FUNCTIONS ======================================================

int get_aff_state()
{
  if (key_is_down(KEY_L | KEY_R))
    return AFF_ROTATE;
  return AFF_NULL;
}

void get_aff_new(OBJ_AFFINE *oaff)
{
  int diff = aff_diffs[aff_state];
  aff_value += (key_is_down(aff_keys[aff_state]) ? diff : -diff);

  switch (aff_state)
  {
  case AFF_ROTATE: // L rotates left, R rotates right
    //aff_value &= SIN_MASK;
    obj_aff_rotate(oaff, aff_value);
    break;
  default: // shouldn't happen
    obj_aff_identity(oaff);
  }
}

void tower_defense_animation()
{
  int turret_pos_x = CENTER_TILE_X, turret_pos_y = CENTER_TILE_Y;
  int robot_pos_x = 0, robot_pos_y = 0;
  int new_state;

  OBJ_ATTR *towerBase = &obj_buffer[0];
  OBJ_ATTR *towerTurret = &obj_buffer[1];
  OBJ_AFFINE *oaff_curr = &obj_aff_buffer[0];
  OBJ_AFFINE *oaff_base = &obj_aff_buffer[1];
  OBJ_AFFINE *oaff_new = &obj_aff_buffer[2];
  tower_init(towerBase, towerTurret, obj_aff_buffer, robot_pos_x, robot_pos_x);

  OBJ_ATTR *robot = &obj_buffer[ROBOT_OBJ_BUFFER_POS];
  robot_init(robot, robot_pos_x, robot_pos_x);

  oam_copy(oam_mem, obj_buffer, 4);

  // oaff_curr = oaff_base * oaff_new
  // oaff_base changes when the aff-state changes
  // oaff_new is updated when it doesn't
  obj_aff_identity(oaff_curr);
  obj_aff_identity(oaff_base);
  obj_aff_identity(oaff_new);

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

    new_state = get_aff_state();
    if (new_state != AFF_NULL) // no change
    {
      if (new_state == aff_state) // increase current transformation
      {
        get_aff_new(oaff_new);
        obj_aff_copy(oaff_curr, oaff_base, 1);
        obj_aff_postmul(oaff_curr, oaff_new);
      }
      else // switch to different transformation type
      {
        obj_aff_copy(oaff_base, oaff_curr, 1);
        obj_aff_identity(oaff_new);
        aff_value = 0;
      }
      aff_state = new_state;
    }

    oam_copy(oam_mem, obj_buffer, 4);
  }
}

int main()
{
  memcpy(&tile_mem[4][0], first_draft_spritesTiles, first_draft_spritesTilesLen);
  memcpy(pal_obj_mem, first_draft_spritesPal, first_draft_spritesPalLen);

  oam_init(obj_buffer, 128);
  REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D;

  tower_defense_animation();

  while (1)
    ;

  return 0;
}
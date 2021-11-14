#include "basicConstants.h"
#include "protagonist.h"
#include "protagonist_sprite_sheet.h"

#include <string.h>
#include <tonc.h>

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer = (OBJ_AFFINE *)obj_buffer;

// === FUNCTIONS ======================================================

void protagonist_animation()
{

  int protagonist_initial_pos_x = CENTER_TILE_X, protagonist_initial_pos_y = CENTER_TILE_Y;

  OBJ_ATTR *protagNeutralSouth = &obj_buffer[0];

  struct Protagonist *protagonist;

  struct Protagonist protag =
      {
          protagonist_initial_pos_x,
          protagonist_initial_pos_y,
          0,
          -1,
          protagNeutralSouth};

  protagonist = &protag;

  protagonist_init(protagonist);

  oam_copy(oam_mem, obj_buffer, 128);

  while (1)
  {
    vid_vsync();
    key_poll();

    protagonist_move(protagonist);

    // move left/right
    protagonist->velocity_x = key_tri_horz();

    // move up/down
    protagonist->velocity_y = key_tri_vert();

    oam_copy(oam_mem, obj_buffer, 128);

    tte_printf("#{es;P}position_x: %d, position_y: %d, velocity_x: %d, velocity_y: %d ",
               protagonist->position_x,
               protagonist->position_y,
               protagonist->velocity_x,
               protagonist->velocity_y);
  }
}

int main()
{
  memcpy(&tile_mem[4][0], protagonist_sprite_sheetTiles, protagonist_sprite_sheetTilesLen);
  memcpy(pal_obj_mem, protagonist_sprite_sheetPal, protagonist_sprite_sheetPalLen);

  oam_init(obj_buffer, 128);
  REG_DISPCNT = DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

  tte_init_chr4c_b4_default(0, BG_CBB(2) | BG_SBB(28));
  tte_init_con();
  tte_set_margins(8, 128, 232, 160);

  protagonist_animation();

  while (1)
    ;

  return 0;
}
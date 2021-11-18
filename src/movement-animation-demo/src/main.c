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
          PROTAGONIST_NEUTRAL_SOUTH_OBJ_BUFFER_POS,
          0,
          0,
          protagNeutralSouth};

  protagonist = &protag;

  protagonist_init(protagonist);

  oam_copy(oam_mem, obj_buffer, 128);

  while (1)
  {
    vid_vsync();
    key_poll();
    if (protagonist->velocity_x != 0 || protagonist->velocity_y != 0)
    {
      protagonist_move(protagonist);
    }

    // move left/right
    protagonist->velocity_x = key_tri_horz();

    // move up/down
    protagonist->velocity_y = key_tri_vert();

    oam_copy(oam_mem, obj_buffer, 128);

    tte_printf("#{es;P}sprite_facing: %d, animation_frame: %d , sprite_tick: %d",
               protagonist->sprite_facing,
               protagonist->animation_frame,
               protagonist->sprite_tick);
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
  tte_set_margins(8, 104, 232, 160);

  protagonist_animation();

  while (1)
    ;

  return 0;
}
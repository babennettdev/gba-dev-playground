#include <string.h>

#include <tonc.h>
#include "hello.h"
#include "sprite_test.h"

const RECT cMenuMainRect = {16, 16, 224, 128};

// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

// Create Hello.
void hello_create(Hello *helloWorld, char *helloString, COLOR color)
{

  helloWorld->string = helloString;
  helloWorld->color = &color;
}

// Prepare for Hello World.
void hello_init(Hello *helloWorld)
{
  // int ii, nn;

  RegisterRamReset(RESET_GFX | RESET_REG_MASK);
  irq_init(NULL);
  irq_add(II_VBLANK, NULL);

  vid_page = vid_mem;
  tte_init_bmp_default(4);
  tte_init_con();
  tte_set_ink(HELLO_PAL_TEXT_BASE);

  // Init palette
  GRIT_CPY(pal_bg_mem, sprite_testPal);
  pal_bg_mem[0] = CLR_BLACK;

  REG_DISPCNT = DCNT_MODE4 | DCNT_BG2;
}

// Run Hello World.
void hello_run(Hello *helloWorld)
{
  // Initial Draw
  hello_draw(helloWorld);

  while (1)
  {
  }
}

// Draw Hello World
void hello_draw(const Hello *helloWorld)
{

  const char *helloWorldString = &helloWorld->string[0];

  RLUnCompVram(sprite_testBitmap, vid_page);

  // Plot item strings
  tte_printf("#{P:%d,%d;ci:%d}%s",
             cMenuMainRect.left, cMenuMainRect.top + 14,
             HELLO_PAL_TEXT_BASE, helloWorldString);
}

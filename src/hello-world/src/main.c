
#include <stdio.h>
#include <string.h>
#include <tonc.h>

#include "hello.h"
#include "all_gfx.h"

int main()
{
  irq_init(NULL);
  irq_add(II_VBLANK, NULL);

  Hello hello;
  hello_create(&hello, "Hello World", HELLO_COLOR);

  while (1)
  {
    hello_init(&hello);
    hello_run(&hello);
  }
}

#include <string.h>

#include <tonc.h>
#include "hello.h"
#include "hello_gfx.h"

const RECT cMenuMainRect = {16, 16, 224, 128};
const RECT cMenuPageRect = {200, 138, 224, 150};

// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

// Create Hello.
void hello_create(Hello *helloWorld, char *helloString, COLOR *color)
{

  helloWorld->string = helloString;
  helloWorld->color = color;
}

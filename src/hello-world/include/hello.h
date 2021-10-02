#ifndef __HELLO_H__
#define __HELLO_H__

#include <tonc.h>

// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------

#define HELLO_PAL_TEXT_BASE 0x18
#define HELLO_COLOR RGB15(24, 8, 24)

// --------------------------------------------------------------------
// TYPES
// --------------------------------------------------------------------

typedef struct Hello
{
  const char *string; // String for Hello World
  COLOR *color;       // Color of the string
} Hello;

// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

void hello_create(Hello *helloWorld, char *helloString, COLOR color);

void hello_init(Hello *helloWorld);
void hello_run(Hello *helloWorld);
void hello_draw(const Hello *helloWorld);

#endif // __HELLO_H__

// EOF
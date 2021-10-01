#ifndef __HELLO_H__
#define __MENU_H__

#include <tonc.h>

// --------------------------------------------------------------------
// TYPES
// --------------------------------------------------------------------

typedef struct Hello
{
  const char *string; // String for Hello World
  COLOR *color        // Color of the string
} Hello;

// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

void hello_create(Hello *helloWorld, char *helloString, COLOR *color);

void hello_init(Hello *helloWorld);
void hello_run(Hello *helloWorld);
void hello_draw(Hello *helloWorld);

#endif // __HELLO_H__

// EOF
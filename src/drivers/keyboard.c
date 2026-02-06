#include "./keyboard.h"

static char get_char() {

  /*ex->
   (take the first bit of these two bin values)
   INB   = 0000 0000
   AND 1 = 0000 0001
   RESULT = 0
   */
  while ((inb(STATUS_PORT) & 1) == 0)
    ;

  uint8_t scancode = inb(DATA_PORT);

  char c = scancode_to_ascii[scancode];

  return c;
}

void initialize_keyboard() 
{
    while(1){
        get_char();
    }
}

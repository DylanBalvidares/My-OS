#include "../drivers/keyboard.h"
#include "../libs/multiboot.h"
#include "../tui/terminal_ui.h"

void kernel_main(const unsigned int magic,
                 const struct multiboot_mmap_entry *mbt) {

  initialize_terminal();
  initialize_keyboard();
  // put_char('h',10,3);
  //  put_str("Hello\nWorld\njeje\n noo \n   see", 0, 0);

  while (1)
    ;
}

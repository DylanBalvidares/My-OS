#include "../drivers/vga_graphics.h"
#include "../libs/multiboot.h"
#include "../libs/strings.h"

void kernel_main(const unsigned int magic, const struct multiboot_tag *mbt)
{

    init_background();

    disable_cursor();
    test();

    while (1)
        ;
}

#include "../drivers/graphics.h"
#include "../libs/multiboot.h"
#include "../libs/strings.h"

void kernel_main(unsigned int magic, struct multiboot_tag *mbt)
{

    char *buffer = 0;

    set_background();
    // print_string("Hello word", 50);

    itoa(123, buffer);
    // char *str = itoa(123, buffer);
    print_string(buffer, 50);

    while (1)
        ;
}

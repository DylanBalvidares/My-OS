#include "../drivers/graphics.h"
#include "../libs/multiboot.h"
#include "../libs/strings.h"
#include "../libs/types.h"

void kernel_main(const unsigned int magic, const struct multiboot_tag *mbt)
{

    char str[4] = {0};

    set_background();

    itoa(123, str);

    print_string(str, 50);

    while (1)
        ;
}

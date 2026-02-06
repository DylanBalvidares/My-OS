#include "./terminal_ui.h"

void initialize_terminal()
{
    clear_bg(); // bg:black,fg:white
    disable_cursor();
    put_str("------ !WELCOME TO MY-OS! ------", 23, 0);
    put_str("#->", 0, 1);
    
}

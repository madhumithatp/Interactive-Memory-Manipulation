#include "main.h"

void help()
    {
        clear_input(input);
        printf("\n\n[Allocate memory]"    " alloc\n");
        printf("[Write in memory]"    " wr\n");
        printf("[Read memory]"        " rd\n");
        printf("[Free memory]"        " free_mem\n");
        printf("[Invert Block]"       "  inv_block\n");
        printf("[Write pattern]"      " wr_pat\n");
        printf("[Verify Pattern]"     "  vrfy_pat\n");
        printf("[Quit]"     "  quit\n\n");

        take_input();
        Interpreter(input);
    }

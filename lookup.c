#include "main.h"

NodeType menu_table[]={ // linear linked list
{ "help", help},
{ "alloc", alloc},
{ "rd", read},
{ "wr", write},
{ "free_mem", free_memory},
{ "wr_pat", write_pattern},
{ "vrfy_pat", verify_pattern},
{ "inv_block", invert_block},
{ "quit", quit},
};

void Interpreter(char *string)
{
    NodeType *pt;
    const int table_length = sizeof(menu_table)/sizeof(*menu_table);
    int row;
    for(row=0; row < table_length; row++)
    {
        pt = &menu_table[row];
        if(strcmp((string), (&pt->cmd))==0)
        {
            pt->fnctPt();
            break;
        }
    }
        if (row == table_length)
        {
        printf("Invalid Option Entered");
        help();
        }

}




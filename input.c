#include "main.h"



void take_input()
{
    scanf("%s",input);
}

void clear_input(char *input1)
{
    input1= "\0";
}

int bounds_check(int mem, int num)
{
    if((mem+num -1) > access.blk_size)
        return 0;
    else
        return 1;
}


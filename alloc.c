#include"main.h"
#include <malloc.h>

void alloc()
{
    clear_input(input);
    /* Go to alloc after back functionality executed*/
	printf("Enter the number of words to be allocated \n"); /*Enter Memory needed to be allocated*/
	scanf("%d",&access.blk_size);
	access.blkptr = (int *)malloc(access.blk_size*4); /*data is int type so 4*Byte=32bits */
	printf("Allocation done!");
	malloc_track=1;                                    /*Update malloc_track variable */
	for(int i= 0; i<=(access.blk_size);i++)             /*Initialize all memory blocks to 0*/
	{
	    *(access.blkptr+i)=0;
	}
    help();  // Display Menu;
}

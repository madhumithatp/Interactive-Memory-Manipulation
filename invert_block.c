#include "main.h"
#include <time.h>

void invert_block()
{
    clock_t t;
    t = clock();
    int sr_no, i, data, num_blocks;
    if(malloc_track==1)
    {

        for (i=0;i< access.blk_size;i++)
        printf("%d  Address of memory - %p\n",i+1,access.blkptr+i);
        printf("Enter the number of memory block you want to invert\n");
        scanf("%d",&num_blocks);
        printf("Enter the start of memory block you want to invert\n");
         do
         {
             scanf("%d",&sr_no);
           if(bounds_check(sr_no,num_blocks))
           {
                t = clock();
                if((sr_no >0) && (sr_no <= (i+1)))
                {
                    for(int i=0;i<num_blocks;i++)
                    {
                        data=*(access.blkptr+sr_no-1+i);
                        data= 0xFFFFFFFF^data;
                        *(access.blkptr+sr_no-1+i)=data;
                        printf(" inverted data at %p address is %08x \n",(access.blkptr+sr_no-1+i),data);
                    }
                    t = clock() - t;
                    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                    printf("Inv block  took %f seconds to execute \n", time_taken);
                    break;
                }
                else
                {
                    printf("Enter Valid Serial Number\n");
                }
           }
            else
            {
                printf("Blocks Out of Bound");
            }
            } while(1);
    }
    else
     {
            printf("Memory not allocated\n");
     }


        help(); // display menu;

}







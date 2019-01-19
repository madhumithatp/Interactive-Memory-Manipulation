#include "main.h"



void read()
{
    int  i, sr_no, num_words;
        clear_input(input);
        if(malloc_track==1)
        {
            for (i=0;i< access.blk_size;i++)
            printf("%d\tAddress of memory - %p\n",i+1,access.blkptr+i);
            printf("Enter the number of data words you want to read\n");
            scanf("%d",&num_words);
            printf("Select the start of address to read\n");
            Serial_no:
                scanf("%d",&sr_no);
                 if(bounds_check(sr_no,num_words))
                 {
                    if((sr_no >0) && (sr_no < (i+2)))
                    {
                        for(int i=0;i<num_words;i++)
                        printf("  data at %p address is %08x \n",(access.blkptr+sr_no-1+i),*(access.blkptr+sr_no-1+i));
                    }
                    else
                    {
                        printf("Enter Valid Serial Number\n");
                        goto Serial_no;
                    }
                }
                else
                {
                printf("Data access out of bound");
                }
        }
        else
        {
            printf("Memory not allocated\n");
        }
        help(); // display menu;
}




















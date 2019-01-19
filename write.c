#include "main.h"

void write()
{
    clear_input(input);
    int i=0, sr_no, data;
    /*Malloc_track sets when malloc is done. check if malloc_track is set*/
       if(malloc_track == 1)
       {
            printf("Select address to write\n");
            /* print all address available  */
            for (i=0;i< access.blk_size;i++)
                printf("%d  Address of memory - %p\n",i+1,access.blkptr+i);
            Serial_no:
            scanf("%d",&sr_no);
            if((sr_no >0) && (sr_no < (i+2)))
            {
                Data_valid:
                printf("Enter data to enter\n");
                scanf("%08x",&data);
            }
            else
            {
                printf("Enter valid number\n");
                goto Serial_no;
            }
            if((data < 0xFFFFFFFF))
            {
        /* to point at selected address. As it is already  pointing at 1 so sr_no-1 will give selected address */
                *(access.blkptr+sr_no - 1) = data;
            }
            else
            {
        /*  Check if data is in Bound*/
                printf("Data out of bound\n");
                goto Data_valid;
            }
       }

       else
       {
            printf("No Memory allocated\n");
       }

        help();
    }


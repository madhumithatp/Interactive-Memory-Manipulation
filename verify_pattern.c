#include "main.h"
#include <time.h>

void verify_pattern()
{
unsigned int ver_val[100];
int blkaddr = blkaddr_num[0];
int numdat = blkaddr_num[1];
int user_blkaddr = 0, user_numdat = 0;
int j = 0;

/*https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/ was referred to for the time calculation*/
clock_t ti;
ti = clock();

printf("Enter address to be verified \n");
 for (j=0;j < access.blk_size; j++)
        {
            printf("%d \t Address of memory \t %p\n",j+1,(access.blkptr+(j*1)));
        }

scanf("%d",&user_blkaddr);
printf("Enter the number of words to be verified \n");
scanf("%d",&user_numdat);

for(int k=0; k < user_numdat;k++)
    {
        ver_val[k] = MyRand(0xABCDEF,0xFFFFFFFF,seed_store[k]);
    }
for(int l=0; l < user_numdat;l++)
    {
         if(*(access.blkptr + (user_blkaddr - 1) + l) == ver_val[l])
            printf("Values Verified at %d \n",l);
        else
            printf("Value mismatch! \t Expected Value:%08x \t Actual Value:%08x \n",ver_val[l],*(access.blkptr + (user_blkaddr - 1) + l));
    }

ti = clock() - ti;
double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds
printf("verify_pattern() took %f seconds to execute \n", time_taken);
help();
}


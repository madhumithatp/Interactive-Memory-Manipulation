/*Inlclude header files*/
#include "main.h"
#include <time.h>

/*Function to generate random numbers*/
/*
 *https://stackoverflow.com/questions/7602919/how-do-i-generate-random-numbers-without-rand-function was referrred to
 *for the random number generation algorithm
 *
 */

unsigned int PSR = 0;           //Variable to store Pseudo-Random Number generated
unsigned int seed_user = 0;    //Variable to store seed entered by the user
unsigned int seed_store[] = {0};
unsigned int blkaddr_num[2] = {0,0};

unsigned int MyRand(unsigned int start_range,unsigned int end_range,int seed)
  {
    /*check for valid range.*/
    if(start_range == end_range) {
        return start_range;
    }

    /*get the random in end-range.*/
    seed = seed + 0x3ADF;
    seed %= end_range;

    /*get the random in start-range.*/
    while(seed < start_range){
        seed = seed + end_range - start_range;
    }

    return seed;
  }


void write_pattern()
{
    /*Measure the amount of time taken for this operation*/
    /*https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/ was referred to for the time calculation*/
    clock_t ti;

   int wrpat_blockaddr = 0;
   int num_words = 0;
   int i_temp = 0, i_ctr = 0;
   int j = 0;

   printf("Enter the address to write data to \n");
        for (j=0;j < access.blk_size; j++)
        {
            printf("%d \t Address of memory \t %p\n",j+1,(access.blkptr+(j*1)));
        }

    do{
        scanf("%d",&wrpat_blockaddr);
        if((wrpat_blockaddr <= 0) || (wrpat_blockaddr > access.blk_size))
            {
                printf("Invalid Memory Address Option! Please enter a valid input \n");
                i_ctr+=1;
            }
            else
            {
                i_ctr = 0;
            }
        }while(i_ctr != 0);

    i_ctr = 0;

    printf("Enter the number of words of data to be written to \n");
    do
    {
        scanf("%d", &num_words);
        i_temp = bounds_check(wrpat_blockaddr,num_words);
        if(i_temp == 0)
        {
            printf("Memory Out of Bounds! Please enter a valid input \n");
            i_ctr = 1;
        }
        else
        {
            i_ctr = 0;
        }
    }while(i_ctr != 0);


    /*Initialize Seeds Array*/
    for(j=0; j<(num_words);j++)
    {
        seed_store[j]=0;
    }

    /*Get the first seed from the user, consequtive seeds are taken from te previous memory block*/
    printf("Enter the Seed in Hexadecimal Format \n");
    scanf("%08x", &seed_user);
    /*First PseudoRandom Number Calculation*/
    ti = clock();
    *(access.blkptr + (wrpat_blockaddr - 1)) = MyRand(0xABCDEF,0xFFFFFFFF,seed_user);
    seed_store[0] = seed_user;

   for(j=1; j< num_words; j++)
    {
        *(access.blkptr + (wrpat_blockaddr - 1) + j) = MyRand(0xABCDEF,0xFFFFFFFF,*(access.blkptr + (wrpat_blockaddr - 1) + (j-1)));
        seed_store[j]= *(access.blkptr + (wrpat_blockaddr - 1) + (j-1));
    }
    for(j=0;j<num_words;j++)
    {
    printf("%08x seed \n",seed_store[j]);
    }
    for(j=0;j < num_words;j++)
    {
         printf(" %d \t %p \t %08x \n",j,(access.blkptr + (wrpat_blockaddr - 1) + j),*(access.blkptr + (wrpat_blockaddr - 1) + j));
    }
    ti = clock() - ti;
    double time_taken = ((double)ti)/CLOCKS_PER_SEC; // in seconds
    printf("write_pattern() took %f seconds to execute \n", time_taken);


   help();
}



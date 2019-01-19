#include "main.h"

void free_memory()
{
   free_memory:
       free(access.blkptr);
       access.blkptr = NULL;
       printf("Allocated Memory is freed!");
       malloc_track=0;
       help();

}

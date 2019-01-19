#include <stdio.h>
#//include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "help.h"
#include "quit.h"
#include "alloc.h"
#include "read.h"
#include "write.h"
#include "input.h"
#include "free_memory.h"
#include "invert_block.h"
#include "write_pattern.h"
#include "verify_pattern.h"
#include "lookup.h"

char input[20];

   typedef struct memory
    {
    int *blkptr;
    int blk_size;
    }location;

 extern location access;
  int malloc_track;

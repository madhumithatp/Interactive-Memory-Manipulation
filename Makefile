*.o = main.o help.o alloc.o input.o menu.o quit.o read.o write.o free_memory.o verify_pattern.o write_pattern.o invert_block.o lookup.o

final : $(*.o)
	gcc -o final $(*.o)

main.o : main.c main.h
	gcc -c main.c
	
help.o : help.c help.h
	gcc -c help.c
	
alloc.o : alloc.c alloc.h
	gcc -c alloc.c
	
lookup.o : lookup.c lookup.h
	gcc -c lookup.c

input.o : input.c input.h
	gcc -c input.c
	
menu.o : menu.c menu.h
	gcc -c menu.c
	
quit.o : quit.c quit.h
	gcc -c quit.c
	
read.o : read.c read.h
	gcc -c read.c
	
write.o : write.c write.h
	gcc -c write.c
	
free_memory.o : free_memory.c free_memory.h
	gcc -c free_memory.c
		
verify_pattern.o : verify_pattern.c verify_pattern.h
	gcc -c verify_pattern.c
	
write_pattern.o : write_pattern.c write_pattern.h
	gcc -c write_pattern.c
	
invert_block.o : invert_block.c invert_block.h
	gcc -c invert_block.c

clean :
	rm final $(*.o)

test : final TestFile
	./final < TestFile
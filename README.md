# ECEN 5813 Principles of Embedded Software
# Project 1 : Interactive Memory Management

Command-line utility to modify and examine memory and provide basic memorey test functionality.

Included command functionlities :
1. Help : The initial greeting on startup must indicate how to invoke the help function. Invoking 
	      the help function will minimally list, to standard output, the available commands and 
		  how to invoke them.
		  
2. Allocate memory : Uses malloc() to allocate a block of memory for use by the application. The 
		  user specifies the number of 32-bit words of memory to allocate.
		  
3. Free memory : Uses free() to release the previously allocated block.

4. Display memory : Display contents of memory in unsigned 32-bit hexadecimal format. The user may 
		  specify an address and the number of 32-bit words to display.

5. Write memory : User specifies an address and the 32-bit unsigned hexadecimal value to write. 
		  Memory at the indicated location is modified accordingly.
		  
6. Invert block : Use an XOR operation to invert all memory bits in a specified area of memory 
		  (address and number of 32-bit words). On completion, this command reports the amount 
		  of time taken to perform the operation.
		  
7. Verify pattern : Verify a pseudo-random pattern in a specified (address and number of 32-bit words)
		  area of memory using a specified seed value. If pattern does not match, command should print 
		  expected and actual value and memory address where the discrepancy was found. On successful 
		  completion, this command reports the amount of time taken to perform the operation.

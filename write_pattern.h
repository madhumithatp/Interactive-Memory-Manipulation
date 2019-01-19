 /*Global variables*/
extern unsigned int PSR;     //Variable to store Pseudo-Random Number generated
extern unsigned int seed_user;    //Variable to store seed entered by the user
extern unsigned int seed_store[];
extern unsigned int blkaddr_num[2];

/*Function Declarations*/
void write_pattern();
unsigned int MyRand(unsigned int start_range,unsigned int end_range,int seed);



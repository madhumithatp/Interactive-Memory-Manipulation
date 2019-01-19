#include "main.h"
void menu()
{
    clear_input(input);
    printf("\n[help] help \n[quit] quit\n");
    take_input();
    Interpreter(input);
}

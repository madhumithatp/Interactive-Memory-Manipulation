
typedef const struct Node{
    char cmd[20];                   // Command
    void (*fnctPt)();
    } NodeType;      // function pointer


//typedef const struct Node NodeType;

extern NodeType menu_table[];

extern void Interpreter(char *string);

#include <stdio.h>
int integer = sizeof(int);
int integerPointer = sizeof(int*);
int longNumber = sizeof(long);
int doublePointer = sizeof(double*);
int characterDoublePointer = sizeof(char**);

int main(int arg, char* argc[])
{
    printf("%d\n%d\n%d\n%d\n%d\n", integer, integerPointer, longNumber, doublePointer, characterDoublePointer);
    return 0;
}

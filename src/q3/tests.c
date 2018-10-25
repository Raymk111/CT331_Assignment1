#include <stdio.h>
#include "genericLinkedList.h"

void printChar(void* chars)
{
    char* str = (char*)chars;
    printf("%s", str);
}

void printInt(void* integer)
{
    int* integer1 = (int*)integer;
    int i = 0;
    do
    {
        printf("%d\t", *(integer1+i));
        i++;
    } while(*(integer1+i) != NULL);
}

void printDouble(void* doubleI)
{
    double* double1 = (double*)doubleI;
    printf("%.2lf\t", *double1);
}

void printFloat(void* floatI)
{
    float* float1 = (float*)floatI;
    printf("%.2f\t", *float1);
}

void runTests(){
    printf("Tests running...\n");
    
    printf("\ntest1\n");
    int i[5] = {0, 1, 2, 3, 712};
    int* iP = &i[0];
    void* strV = iP;
    listElement* l = createEl(strV, &printInt);
    //Test create and traverse
    printEl(l);
    printf("\n");
    
    //...
    /*
    char* str = "MUP";
    void* strV = str;
    int i[4] = {0, 1, 2, 3};
    int* iP = &i[0];
    double mup = 1.1;
    double* mupP = &mup;
    strV = mupP;
    void (*fp)(void*);
    fp = &printDouble;
    (*fp)(strV);*/
    printf("\nTests complete.\n");
}

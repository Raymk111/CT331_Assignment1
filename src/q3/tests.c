#include <stdio.h>
#include "genericLinkedList.h"

void printChar(void* chars, size_t size)
{
    char* str = (char*)chars;
    printf("%s", str);
}

void printInt(void* integer, size_t size)
{
    int* integer1 = (int*)integer;
    int i = 0;
    while(i < size)
    {
        printf("%d\t", *(integer1+i));
        i++;
    }
}

void printDouble(void* doubleI, size_t size)
{
    double* double1 = (double*)doubleI;
    int i = 0;
    while(i < size)
    {
        printf("%.2lf\t", *(double1+i));
        i++;
    }
}

void printFloat(void* floatI, size_t size)
{
    float* float1 = (float*)floatI;
    int i = 0;
    while(i < size)
    {
        printf("%.2f\t", *(float1+i));
        i++;
    }
}

void runTests(){
    printf("Tests running...\n");
    
    printf("\nTest1 - Adding Integer Array in List\n");
    int integers[5] = {0, 1, 2, 3, 712};
    int* iP = &integers[0];
    void* strV = iP;
    listElement* l = createEl(strV, 5, &printInt);
    //Test create and traverse
    printEl(l);
    printf("\n");
    
    printf("\nTest2 - Adding Char Array in List\n");
    char chars[6] = "Muppa";
    char* charsP = &chars[0];
    strV = charsP;
    insertAfter(l, strV, 5, &printChar);
    traverse(l);
    printf("\n");
    
    printf("\nTest3 - Adding Double Array in List\n");
    double doubles[5] = {77.233, 555.43, 331.543, 3.6676, 712.1224};
    double* doublesP = &doubles[0];
    strV = doublesP;
    enqueue(&l, strV, 5, &printDouble);
    traverse(l);
    printf("\n");
    
    printf("\nTest3 - Adding Float Array in List\n");
    float floats[5] = {0.233, 1.43, 2.543, 3.6676, 712.1224};
    float* floatsP = &floats[0];
    strV = floatsP;
    push(&l, strV, 5, &printFloat);
    traverse(l);
    printf("\n");
    
    printf("FinalTest - Pop, Dequeue and deleteAfter\n");
    listElement* test = pop(&l);
    printf("Popped - ");
    printEl(test);
    
    printf("Dequeued - ");
    test = dequeue(&l);
    printEl(test);
    
    printf("Deleted After Head - ");
    deleteAfter(l);
    traverse(l);
    
    printf("\n");
    
    printf("\nTests complete.\n");
}

#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
    printf("Tests running...\n");
    
    printf("\ntest1\n");
    listElement* l = createEl("Test String (1).", 30);
    //printf("%s\n%p\n", l->data, l->next);
    //Test create and traverse
    traverse(l);
    printf("\n");
    
    //Test insert after
    printf("\ntest2\n");
    listElement* l2 = insertAfter(l, "another string (2)", 30);
    insertAfter(l2, "a final string (3)", 30);
    traverse(l);
    printf("\n");

    // Test delete after
    printf("\ntest3\n");
    deleteAfter(l);
    traverse(l);
    printf("\n");
    
    //test Length
    printf("\ntest4\n");
    printf("\nLength = %d\n", length(l));
    
    //push test
    printf("\ntest5\n");
    push(&l, "mup", 30);
    traverse(l);
    
    //pop test
    printf("\ntest6\n");
    listElement* test = pop(&l);
    printEl(test);
    printEl(l);
    printf(" = Element Removed\nAfter removal\n");
    traverse(l);
    printf("\nLength = %d\n", length(l));
    
    //enqueue test
    printf("\ntest7\n");
    enqueue(&l, "mup", 30);
    traverse(l);
    printf("\nLength = %d\n", length(l));
    
    //dequeue test
    printf("\ntest8\n");
    test = dequeue(l);
    printEl(test);
    printf(" = Element Removed\nAfter removal\n");
    traverse(l);
    printf("\nLength = %d\n", length(l));
    test = dequeue(l);
    printEl(test);
    printf(" = Element Removed\nAfter removal\n");
    traverse(l);
    printf("\nLength = %d\n", length(l));
    test = dequeue(l);
    printEl(test);
    printf(" = Element Removed\nAfter removal\n");
    traverse(l);
    printf("\nLength = %d\n", length(l));
    test = dequeue(l);
    printEl(test);
    printf(" = Element Removed\nAfter removal\n");
    traverse(l);
    printf("\nLength = %d\n", length(l));
    
    
    printf("\nTests complete.\n");
}

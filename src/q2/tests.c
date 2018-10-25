#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
    printf("Tests running...\n");
    
    printf("Test1\n");
    listElement* l = createEl("Test String (1).", 30);
    //printf("%s\n%p\n", l->data, l->next);
    //Test create and traverse
    traverse(l);
    printf("Length = %d\n", length(l));
    
    //Test insert after
    printf("\nTest2\n");
    listElement* l2 = insertAfter(l, "another string (2)", 30);
    insertAfter(l2, "a final string (3)", 30);
    traverse(l);
    printf("Length = %d\n", length(l));

    // Test delete after
    printf("\nTest3\n");
    deleteAfter(l);
    traverse(l);
    
    //test Length
    printf("\nTest4\n");
    printf("Length = %d\n", length(l));
    
    //push test
    printf("\nTest5\n");
    push(&l, "1", 30);
    push(&l, "2", 30);
    push(&l, "3", 30);
    traverse(l);
    printf("Length = %d\n", length(l));
    
    //pop test
    printf("\nTest6\n");
    listElement* test = pop(&l);
    while(length(l) >= 1)
    {
        test = pop(&l);
        printf("Popped - ");
        printEl(test);
    }
    printf(" = Element Removed\nAfter removal - Traverse should be empty\n");
    traverse(l);
    printf("Length = %d\n", length(l));
    
    //enqueue test
    printf("\nTest7 - Enqueue 1, 2, 3 to whats left\n");
    enqueue(&l, "1", 30);
    enqueue(&l, "2", 30);
    enqueue(&l, "3", 30);
    traverse(l);
    printf("Length = %d\n", length(l));
    
    //dequeue test
    printf("\nTest8 - dequeue all elements\n");
    while(length(l) >= 1)
    {
        test = dequeue(&l);
        printf("Dequeued - ");
        printEl(test);
    }
    printf("Traverse Should Print Nothing - ");
    traverse(l);
    
    printf("\nTests complete.\n");
}

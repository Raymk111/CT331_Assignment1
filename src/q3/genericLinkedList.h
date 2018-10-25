
#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size, void (*fp)(void*, size_t));

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void (*fp)(void*, size_t));

//Delete the element after the given el
void deleteAfter(listElement* after);

//get length of list
int length(listElement* start);

//push() add to the top of the list
void push(listElement** list, void* data, size_t size, void (*fp)(void*, size_t));

//print an element
void printEl(listElement* list);

//pop from top and return
listElement* pop(listElement** list);

//enqueue to head of list
void enqueue(listElement** list, void* data, size_t size, void (*fp)(void*, size_t));

//dequeue for end of list and delete
listElement* dequeue(listElement** list);

#endif

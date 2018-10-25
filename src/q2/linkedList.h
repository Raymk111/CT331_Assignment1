#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, char* data, size_t size);

//Delete the element after the given el
void deleteAfter(listElement* after);

//get length of list
int length(listElement* start);

//push() add to the top of the list
void push(listElement** list, char* data, size_t size);

//print an element
void printEl(listElement* list);

//pop from top and return
listElement* pop(listElement** list);

//enqueue to head of list
void enqueue(listElement** list, char* data, size_t size);

//dequeue for end of list and delete
listElement* dequeue(listElement** list);

#endif

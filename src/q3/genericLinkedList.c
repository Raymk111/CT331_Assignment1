#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
    void* data;
    size_t size;
    struct listElementStruct* next;
    void (*fp)(void*, size_t);
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size, void (*fp)(void*, size_t)){
    listElement* e = malloc(sizeof(listElement));
    if(e == NULL){
        //malloc has had an error
        return NULL; //return NULL to indicate an error.
    }
    
    e->data = data;
    e->next = NULL;
    e->size = size;
    e->fp = fp;
    return e;
}

int length(listElement* start)
{
    if(start == NULL)
    {
        return 0;
    }
    int length = 1;
    listElement* curr = start;
    while(curr->next != NULL)
    {
        curr = curr->next;
        length++;
    }
    return length;
}

void push(listElement** list, void* data, size_t size, void (*fp)(void*, size_t))
{
    listElement* newEl = createEl(data, size, fp);
    newEl->next = *list;
    
    *list = newEl;
}

listElement* pop(listElement** list)
{
    if(list == NULL)
        return NULL;
    
    listElement* retElement = *list;
    if(retElement->next != NULL)
    {
        listElement* newTop = retElement->next;
        *list = newTop;
        retElement->next = NULL;
    }
    else
    {
        *list = NULL;
    }
    
    return retElement;
}

void printEl(listElement* list)
{
    if(list != NULL)
    {
        list->fp(list->data, list->size);
        printf("\n");
    }
}

//Prints out each element in the list
void traverse(listElement* start)
{
    
    listElement* current = start;
    while(current != NULL)
    {
        current->fp(current->data, current->size);
        printf("\n");
        current = current->next;
    }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
/*listElement* insertAfter(listElement* el, char* data, size_t size){
    listElement* newEl = createEl(data, size);
    listElement* next = el->next;
    newEl->next = next;
    el->next = newEl;
    return newEl;
}*/

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void (*fp)(void*, size_t)){
    listElement* newEl = createEl(data, size, fp);
    listElement* next = el->next;
    newEl->next = next;
    el->next = newEl;
    return newEl;
}

//same as push as you are just adding to the head of the list - no redundancy by calling push
void enqueue(listElement** list, void* data, size_t size, void (*fp)(void*, size_t))
{
    push(list, data, size, fp);
}

listElement* dequeue(listElement** list)
{
    listElement* curr = *list;
    listElement* ret = *list;
    int len = length(*list);
    int i = 1;
    
    if(len == 1)
    {
        *list = NULL;
        return ret;
    }
    
    while(i < len-1)
    {
        curr = curr -> next;
        i++;
    }
    
    if(len > 1)
    {
        ret = curr->next;
        curr->next = NULL;
    }
    
    return ret;
}

//Delete the element after the given el
void deleteAfter(listElement* after){
    listElement* delete = after->next;
    listElement* newNext = delete->next;
    after->next = newNext;
    //need to free the memory because we used malloc
    free(delete);
}

/** @file MyDLL_Module.c
 * @brief Source file for the implementation of a Doubly Linked List (DLL)
 * 
 * MyDLL_Module.c has the implementations for the functions defined in the header file.
 * 
 * @authors Henrique Ferreira\n Rui Borregana
 * @date 12 Mar 2025
 * @bug -------------rever no fim-------------
 */
#include "MyDLL.h"
#include <string.h>
#include <stdlib.h>




void MyDLLInit(list *dll) {
    dll->head = -1;
    dll->tail = -1;
    dll->count = 0;
    for (int i = 0; i < MAX_SIZE_NODE; i++) {
        dll->nodelist[i].prev = -1;
        dll->nodelist[i].next = -1;
        dll->available[i] = 1;  // Mark all nodes as available
    }
}

void MyDLLInsert(list *dll, uint16_t key, const char *data){}

void MyDLLRemove(list *dll, uint16_t id){}

char* MyDLLFind(list *dll, uint16_t id){}

char* MyDLLFindNext(list *dll, uint16_t id){}

char* MyDLLFindPrevious(list *dll, uint16_t id){}

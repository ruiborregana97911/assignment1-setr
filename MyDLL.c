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


void MyDLLInit(list *dll){}

void MyDLLInsert(list *dll, uint16_t key, const char *data){}

void MyDLLRemove(list *dll, uint16_t id){}

char* MyDLLFind(list *dll, uint16_t id){}

char* MyDLLFindNext(list *dll, uint16_t id){}

char* MyDLLFindPrevious(list *dll, uint16_t id){}

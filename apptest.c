/** @file apptest.c
 * @brief Test aplication for MyDLL_Module
 * 
 * apptest.c contains only the main function that provides the test
 * 
* @authors Henrique Ferreira\n Rui Borregana
 * @date 12 Mar 2025
 * @bug -------------rever no fim-------------
 */

#include "MyDLL.h"
#include <string.h>
#include <stdio.h>


int main() {
    list myList;
    MyDLLInit(&myList);

    // Check if initialization was successful
    printf("Initial state:\n");
    printf("Head: %d\n", myList.head);
    printf("Tail: %d\n", myList.tail);
    printf("Count: %d\n", myList.count);
    
    // Insert test nodes
    MyDLLInsert(&myList, 10, "ola");
    MyDLLInsert(&myList, 20, "bom");
    MyDLLInsert(&myList, 30, "dia");
    
    // Print list state after insertions
    printf("\nAfter insertions:\n");
    printf("Head: %d\n", myList.head);
    printf("Tail: %d\n", myList.tail);
    printf("Count: %d\n", myList.count);
    
    for (int i = 0; i < MAX_SIZE_NODE; i++) {
        if (myList.available[i] == 0) {
            printf("Node at index %d - Key: %d, Data: %s, Prev: %d, Next: %d\n",
                   i, myList.nodelist[i].key, myList.nodelist[i].data,
                   myList.nodelist[i].prev, myList.nodelist[i].next);
        }
    }
    
    // Remove a node
    printf("\nRemoving Node with key 20...\n");
    MyDLLRemove(&myList, 20);
    
    // Print list state after removal
    printf("\nAfter removal:\n");
    printf("Head: %d\n", myList.head);
    printf("Tail: %d\n", myList.tail);
    printf("Count: %d\n", myList.count);
    
    for (int i = 0; i < MAX_SIZE_NODE; i++) {
        if (myList.available[i] == 0) {
            printf("Node at index %d - Key: %d, Data: %s, Prev: %d, Next: %d\n",
                   i, myList.nodelist[i].key, myList.nodelist[i].data,
                   myList.nodelist[i].prev, myList.nodelist[i].next);
        }
    }
    
    
    // Insert test nodes
    MyDLLInsert(&myList, 100, "cem");
    MyDLLInsert(&myList, 230, "douzentos e trinta");
    MyDLLInsert(&myList, 400, "quatrocentos");
    
    
    printf("\nFinding Node with key ??..\n");
    char *data_tst = MyDLLFind(&myList, 1000);
    
    if(data_tst != NULL){
		printf("Node data: %s\n", data_tst);
		}


    // Print list state after insertions
    printf("\nAfter insertions:\n");
    printf("Head: %d\n", myList.head);
    printf("Tail: %d\n", myList.tail);
    printf("Count: %d\n", myList.count);
    
    for (int i = 0; i < MAX_SIZE_NODE; i++) {
        if (myList.available[i] == 0) {
            printf("Node at index %d - Key: %d, Data: %s, Prev: %d, Next: %d\n",
                   i, myList.nodelist[i].key, myList.nodelist[i].data,
                   myList.nodelist[i].prev, myList.nodelist[i].next);
        }
    }
    
    
    data_tst = MyDLLFindNext(&myList, 400);
   
    
    printf("\n");
    if(data_tst != NULL){
		printf("Node data: %s\n", data_tst);
		}

	data_tst = MyDLLFindPrevious(&myList, 10);

    printf("\n");
    if(data_tst != NULL){
		printf("Node data: %s\n", data_tst);
		}
    
    return 0;
}

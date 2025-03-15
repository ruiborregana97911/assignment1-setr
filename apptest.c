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
    MyDLLInit(&myList, 10, 20);

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
    MyDLL_print(&myList);
    
    // Remove a node
    printf("\nRemoving Node with key 20...\n");
    MyDLLRemove(&myList, 20);
    
    // Print list state after removal
    printf("\nAfter removal:\n");
    MyDLL_print(&myList);
    
    
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
	MyDLL_print(&myList);
    
    
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
		
		
	MyDLL_print(&myList);	
		
		
	MyDLLDestroy(&myList);	
    
    printf("\n");
	MyDLL_print(&myList);
    
    return 0;
}

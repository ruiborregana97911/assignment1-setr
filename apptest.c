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
    printf("Head: %d\n", myList.head);
    printf("Tail: %d\n", myList.tail);
    printf("Count: %d\n", myList.count);
    
    // Check available nodes
    printf("Available nodes: ");
    for (int i = 0; i < MAX_SIZE_NODE; i++) {
        printf("%d ", myList.available[i]);
    }
    printf("\n");
    
    return 0;
}

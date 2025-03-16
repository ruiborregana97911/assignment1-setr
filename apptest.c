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
    MyDLLInit(&myList, 5, 20);

    // Check if initialization was successful
	printf("### Test 1: Initialization ###\n");
	MyDLL_print(&myList);
    
    // Insert test nodes
    printf("### Test 2: Insertion of elements ###\n");
    MyDLLInsert(&myList, 10, "ola");
    MyDLLInsert(&myList, 20, "bom");
    MyDLLInsert(&myList, 30, "dia");
    
    MyDLL_print(&myList);
    
    printf("Addind repeated key...\n");
    MyDLLInsert(&myList, 30, "noite");	//repeated key
    
    
    // Print list state after insertions
    MyDLL_print(&myList);
    
    //Test Find
    printf("### Test 3: Finding elements ###\n\n");
    printf("Find(20): %s\n", MyDLLFind(&myList, 20));
    printf("Find(80): %s\n", MyDLLFind(&myList, 80));	//Non existent
    printf("\n");
    
    //Test FindNext and FindPrevious
    printf("### Test 4: Finding elements ###\n\n");
    printf("FindNext(10): %s\n", MyDLLFindNext(&myList, 10));
    printf("FindNext(30): %s\n", MyDLLFindNext(&myList, 30));	//last element
    printf("FindNext(80): %s\n", MyDLLFindNext(&myList, 80));	//Non existent
    printf("\n");
    printf("FindPrevious(30): %s\n", MyDLLFindPrevious(&myList, 30));
    printf("FindPrevious(10): %s\n", MyDLLFindPrevious(&myList, 10));	//first element
    printf("FindPrevious(80): %s\n", MyDLLFindPrevious(&myList, 80));	//Non existent
    printf("\n");
    

    // Remove a node
    printf("### Test 5: Removing elements ###\n");
    printf("\nRemoving Node with key 20\n");
    
    MyDLL_print(&myList);	//before removing
    
    MyDLLRemove(&myList, 20);
    
    // Print list state after removal
    MyDLL_print(&myList);
    
    // Testing removing elements that dont exist
    printf("### Test 6: Removing non existent elements ###\n");
    printf("\nRemoving Node with key 80\n");
    MyDLLRemove(&myList, 80);
    MyDLL_print(&myList);
    
    // Removing first and last elements
    printf("### Test 7: Removing first and last elements ###\n\n");
    MyDLLRemove(&myList, 10);
    MyDLLRemove(&myList, 30);
    
    MyDLL_print(&myList);
    
    printf("### Test 8: Testing Limits of elements Insertion ###\n\n");
    MyDLLInsert(&myList, 44, "Maria");
    MyDLLInsert(&myList, 55, "Paulo");
    MyDLLInsert(&myList, 33, "Joana");
    MyDLLInsert(&myList, 100, "Rafael");
    MyDLLInsert(&myList, 15, "Toni");
    
    MyDLL_print(&myList);
    
    printf("Adding extra element ...\n");
    MyDLLInsert(&myList, 78, "Ana");	//extra element
    
    MyDLL_print(&myList);
    
    
    
    printf("\n### Test xx: Freeing allocated memory ###\n");
	MyDLLDestroy(&myList);	
    
	MyDLL_print(&myList);
    
    return 0;
}

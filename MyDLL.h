/** @file MyDLL.h
 * @brief Header file for the implementation of a Doubly Linked List (DLL)
 * 
 * MyDLL.h contains the structures and functions for the Doubly Linked List module in C. 
 * 
 * @authors Henrique Ferreira\n Rui Borregana
 * @date 12 Mar 2025
 * @bug -------------rever no fim-------------
 */
#ifndef _MyDLL_H
#define _MyDLL_H

/**
 * @def MAX_SIZE_DATA
 * @brief Maximum value assigned to the data array of each element
 */
#define MAX_SIZE_DATA 64
/**
 * @def MAX_SIZE_NODE
 * @brief Maximum number of elements assigned to the Doubly Linked List
 */
#define MAX_SIZE_NODE 10

#include <stdio.h>
#include <stdint.h>

/**
 * @struct node
 * @brief Structure representing the elements in the Doubly Linked List
 *
 * This structure has one unique key chosen by the user that identifies the element itself, a char array that 
 * stores information called data and contains a reference to the previous and 
 * next element in the list. 
 * 
 */ 
typedef struct {
	uint16_t key;	/**< Unique node identifier */
	char data[MAX_SIZE_DATA]; /**< Data saved in the node */
	int prev; /**< Key of the previous node */
	int next; /**< Key of the next node */
}node;
/**
 * @struct list
 * @brief Structure representing the Doubly Linked List (DLL)
 * 
 * This structure stores all the elements, contains a reference to the 
 * first and last element and counts the number of elements on the list.
 * 
 */
typedef struct {
	node nodelist[MAX_SIZE_NODE]; /**< Array of nodes in the list */
	int head; /**< Key of the first node in the DLL */
	int tail; /**< Key of the last node in the DLL */
	int count; /**< Number of nodes in the DLL (node counter) */
}list;

/**
 * @brief MyDLLInit initializes the Doubly Linked List
 *
 * This function initializes the list by setting the head and tail keys to -1 and the node counter to zero.
 *
 *
 * @param[in] *dLL - Pointer to the list
 * @return Doesn't return anything
 */
void MyDLLInit(list *dll);
/**
 * @brief MyDLLInsert adds an element to the Doubly Linked List
 *
 * This functions asks the user for a key and data then adds an element with it's own unique key and any size valid data into the Doubly Linked List
 * Also updates the node counter so its always equal or less than the MAX_SIZE_NODE and updadtes the head an tail Keys
 *
 * @param[in] *dLL - Pointer to the Doubly Linked List\n
 * @return Doesn't return anything
 */
void MyDLLInsert(list *dll);
/**
 * @brief MyDLLRemove removes an element/node from the Doubly Linked List
 *
 * This function removes and element from the list, identified by its key
 * Also updates the node and updadtes the head an tail Keys if necessary
 * 
 * @param[in] *dLL Pointer to the Doubly Linked List
 * @param[in] id Element identifier 
 * Doesn't return anything.
 */
void MyDLLRemove(list *dll, uint16_t id);
/**
 * @brief MyDLLFind returns a node from the Doubly Linked List
 *
 * This function askes the user for a key and returns the data of an element, identified by its key, or error if it does not exist
 * 
 * @param[in] *dLL Pointer to the Doubly Linked List
 * @return pointer to the intended node if the provided key is valid
 * @return NULL if the provided key is invalid
 */
char MyDLLFind(list *dll);
/**
 * @brief MyDLLFindNext returns a node from the Doubly Linked List
 *
 * This function askes the user for a key and returns the data of the next element or error if it does not exist
 * 
 * @param[in] *dLL Pointer to the Doubly Linked List
 * @return pointer to the intended node if the provided key/id or keywords "next"/"prev" are valid
 * @return NULL if the provided key/id or keywords "next"/"prev" are invalid
 */
char MyDLLFindNext(list *dll);
/**
 * @brief MyDLLFindPrevious returns a node from the Doubly Linked List
 *
 * This function askes the user for a key and returns the data of the previous element or error if it does not exist
 * 
 * @param[in] *dLL Pointer to the Doubly Linked List
 * @return pointer to the intended node if the provided key/id or keywords "next"/"prev" are valid
 * @return NULL if the provided key/id or keywords "next"/"prev" are invalid
 */
char MyDLLFindPrevious(list *dll);

#endif


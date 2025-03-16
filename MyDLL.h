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

#include <stdio.h>
#include <stdint.h>

/**
 * @struct node
 * @brief Structure representing a node in the doubly linked list
 *
 * This structure contains a unique key assigned by the user to identify the node,
 * a character array to store data, and references to the previous and next nodes in the list.
 */
typedef struct {
    uint16_t key;              /**< Unique node identifier */
    char *data;  /**< Data stored in the node */
    int16_t prev;              /**< Key of the previous node (-1 for null) */
    int16_t next;              /**< Key of the next node (-1 for null) */
} node;
/**
 * @struct list
 * @brief Structure representing the Doubly Linked List (DLL)
 *
 * This structure contains all the elements, a reference to the first and last nodes,
 * and a counter for the number of nodes in the list. It also maintains an availability array
 * to track free nodes.
 */
typedef struct {
    node *nodelist; /**< Array of nodes in the list */
    int head;                     /**< Key of the first node in the DLL */
    int tail;                     /**< Key of the last node in the DLL */
    int count;                    /**< Number of nodes in the DLL */
    int *available;  /**< Array to track free nodes (1 = free, 0 = occupied) */
	uint16_t max_size_node;			/**< Maximum number of elements assigned to the Doubly Linked List*/
	uint16_t max_size_data;			/**< Maximum value assigned to the data array of each element*/
	
} list;

/**
 * @brief MyDLLInit initializes the Doubly Linked List
 *
 * This function initializes the list by setting the head and tail keys to -1,
 * the node counter to zero, and marking all nodes as available. This function
 * sets the maximum number of elements in the list and also the maximum size for the data.
 *
 * @param[in] *dll Pointer to the list
 * @param[in] node_size Max number of elements of the DLL
 * @param[in] data_size Max size of the data of DLL
 */
void MyDLLInit(list *dll, uint16_t node_size, uint16_t data_size);
/**
 * @brief MyDLLInsert adds an element to the Doubly Linked List
 *
 * This function adds an element with a unique key and user-provided data into the DLL.
 * It updates the node counter and adjusts the head and tail references accordingly.
 *
 * @param[in] *dll Pointer to the DLL
 * @param[in] key Unique identifier for the new node
 * @param[in] *data Data to be stored in the node
 */
void MyDLLInsert(list *dll, uint16_t key, const char *data);
/**
 * @brief MyDLLRemove removes an element/node from the Doubly Linked List
 *
 * This function removes a node identified by its key.
 * It also updates the node counter and adjusts the head and tail references if necessary.
 *
 * @param[in] *dll Pointer to the DLL
 * @param[in] id Identifier of the node to be removed
 */
void MyDLLRemove(list *dll, uint16_t id);
/**
 * @brief MyDLLFind returns a node from the Doubly Linked List
 *
 * This function searches for a node by its key and returns its data.
 * If the node does not exist, it returns NULL.
 *
 * @param[in] *dll Pointer to the DLL
 * @param[in] id Identifier of the node to find
 * @return Pointer to the data if the node is found, NULL otherwise
 */
char* MyDLLFind(list *dll, uint16_t id);
/**
 * @brief MyDLLFindNext returns a node from the Doubly Linked List
 *
 * This function searches for a node by its key and returns the data of the next node.
 * If the next node does not exist, it returns ERROR message.
 *
 * @param[in] *dll Pointer to the DLL
 * @param[in] id Identifier of the current node
 * @return Pointer to the data of the next node if it exists, ERROR message otherwise
 */
char* MyDLLFindNext(list *dll, uint16_t id);
/**
 * @brief MyDLLFindPrevious returns a node from the Doubly Linked List
 *
 * This function searches for a node by its key and returns the data of the previous node.
 * If the previous node does not exist, it returns ERROR message.
 *
 * @param[in] *dll Pointer to the DLL
 * @param[in] id Identifier of the current node
 * @return Pointer to the data of the previous node if it exists, ERROR message otherwise
 */
char* MyDLLFindPrevious(list *dll, uint16_t id);

/**
 * @brief MyDLLDestroy frees the allocated memory of a specific DLL
 * 
 * This funtion frees the memory allocated when funtion MyDLLInit() is called
 * 
 * @param[in] *dll Pointer to the DLL
 */
void MyDLLDestroy(list *dll);

/**
 * @brief MyDLL_print shows all information inside the Doubly Linked List
 * 
 * @param[in] *dll Pointer to the DLL
 */

void MyDLL_print(list *dll);

#endif


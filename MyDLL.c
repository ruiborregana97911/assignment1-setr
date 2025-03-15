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




void MyDLLInit(list *dll, uint16_t node_size, uint16_t data_size) {
    
    dll->max_size_node = node_size;
    dll->max_size_data = data_size;
    
    dll->nodelist = malloc(node_size * sizeof(node));
    dll->available = malloc(node_size * sizeof(int));
    
    for(int i=0; i < node_size; i++){
		dll->nodelist[i].prev = -1;
        dll->nodelist[i].next = -1;
        dll->available[i] = 1;  // Mark all nodes as available
        dll->nodelist[i].data = malloc(data_size * sizeof(char));
	}
    
    dll->head = -1;
    dll->tail = -1;
    dll->count = 0;

}

void MyDLLInsert(list *dll, uint16_t key, const char *data) {
    if (dll->count >= dll->max_size_node) {
        printf("List is full! Cannot insert new node.\n");
        return;
    }
    
    // Find an available index
    int index = -1;
    for (int i = 0; i < dll->max_size_node; i++) {
        if (dll->available[i] == 1) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("No available space found!\n");
        return;
    }
    
    // Initialize the new node
    dll->nodelist[index].key = key;
    strncpy(dll->nodelist[index].data, data, dll->max_size_data);
    dll->nodelist[index].prev = -1;
    dll->nodelist[index].next = -1;
    dll->available[index] = 0; // Mark as occupied
    
    // Insert into the list
    if (dll->head == -1) { // Empty list case
        dll->head = index;
        dll->tail = index;
    } else { // Append to the end
        dll->nodelist[dll->tail].next = index;
        dll->nodelist[index].prev = dll->tail;
        dll->tail = index;
    }
    
    dll->count++;
}

void MyDLLRemove(list *dll, uint16_t id) {
    int index = -1;
    for (int i = 0; i < dll->max_size_node; i++) {
        if (dll->available[i] == 0 && dll->nodelist[i].key == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Node with key %d not found.\n", id);
        return;
    }
    
    // Adjust pointers
    if (dll->nodelist[index].prev != -1) {
        dll->nodelist[dll->nodelist[index].prev].next = dll->nodelist[index].next;
    } else {
        dll->head = dll->nodelist[index].next;
    }
    
    if (dll->nodelist[index].next != -1) {
        dll->nodelist[dll->nodelist[index].next].prev = dll->nodelist[index].prev;
    } else {
        dll->tail = dll->nodelist[index].prev;
    }
    
    // Mark as available
    dll->available[index] = 1;
    dll->count--;
    printf("Node with key %d removed.\n", id);
}


char* MyDLLFind(list *dll, uint16_t id){
	
	for(int i=0;i < dll->max_size_node;i++){
		if(!dll->available[i] && dll->nodelist[i].key == id){
			return dll->nodelist[i].data;
		}
	}

	return "ERROR: key not found!";
}

char* MyDLLFindNext(list *dll, uint16_t id){
	
		for(int i=0;i < dll->max_size_node;i++){
			if(!dll->available[i] && dll->nodelist[i].key == id){
				int16_t next_id = dll->nodelist[i].next;
				
				if(next_id != -1){
					return dll->nodelist[next_id].data;
				}
				return "ERROR: No next node!";
			}
		}
		
	return "ERROR: key not found!";
}

char* MyDLLFindPrevious(list *dll, uint16_t id){
	
		for(int i=0;i < dll->max_size_node;i++){
			if(!dll->available[i] && dll->nodelist[i].key == id){
				int16_t prev_id = dll->nodelist[i].prev;
				
				if(prev_id != -1){
					return dll->nodelist[prev_id].data;
				}
				return "ERROR: No previous node!";
			}
		}
	
	return "ERROR: key not found!";
}

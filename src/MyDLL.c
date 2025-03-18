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
    if (!dll->nodelist) {
        printf("Memory allocation failed for nodelist!\n");
        return;
    }
    
    dll->available = malloc(node_size * sizeof(int));
    if (!dll->available) {
        printf("Memory allocation failed for available list!\n");
        free(dll->nodelist);
        return;
    }
    
    for (int i = 0; i < node_size; i++) {
        dll->nodelist[i].prev = -1;
        dll->nodelist[i].next = -1;
        dll->available[i] = 1;  // Marca todos os nós como disponíveis
        
        dll->nodelist[i].data = malloc(data_size * sizeof(char));
        if (!dll->nodelist[i].data) {
            printf("Memory allocation failed for node data at index %d!\n", i);
            for (int j = 0; j < i; j++) {
                free(dll->nodelist[j].data);
            }
            free(dll->nodelist);
            free(dll->available);
            return;
        }
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
    
    //search for repeated keys
    for(int i = 0; i < dll->max_size_node; i++){
		if(dll->nodelist[i].key == key){
			printf("Key already exists! \n");
			return;
		}	
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

void MyDLLDestroy(list *dll){
	
	for(int i=0; i < dll->max_size_node; i++){
		free(dll->nodelist[i].data);	
	}	
	free(dll->nodelist);
	free(dll->available);
	
	dll->head = -1;
    dll->tail = -1;
    dll->count = 0;
	
}

void MyDLL_print(list *dll){
	printf("\n----- Doubly Linked List -----\n");		
	printf("Head: %d | Tail: %d | Count: %d\n", dll->head, dll->tail, dll->count);

    for (int i = 0; i < dll->max_size_node; i++) {
        if (dll->available[i] == 0) {
            printf("Node[%d] - Key: %d | Data: '%s' | Prev: %d | Next: %d\n",
                   i, dll->nodelist[i].key, dll->nodelist[i].data,
                   dll->nodelist[i].prev, dll->nodelist[i].next);
        }
    }	
	printf("------------------------------\n\n");
}

void MyDLLSort(list *dll, bool ascending){
	if(dll->count <=1){return;}	//list empty or just have  onde element
	
	for(int i=0; i < dll->count - 1; i++){
		for(int j=0; j < dll->count - i - 1; j++){
			int idx1 = j;
			int idx2 = j + 1;
			
			//checks if swap is needed
			if((ascending && dll->nodelist[idx1].key > dll->nodelist[idx2].key) || 
			(!ascending && dll->nodelist[idx1].key < dll->nodelist[idx2].key)){
				
				//swapps elements
				node aux= dll->nodelist[idx1];
				dll->nodelist[idx1] = dll->nodelist[idx2];
				dll->nodelist[idx2] = aux;
			}	
		}
	}
	
	
	//updates the indexes after sorting
	for(int i=0;i < dll->count;i++){
		if(i == 0) {
			dll->nodelist[i].prev = -1;	//first element does not have a pervious
			
		} else{
			dll->nodelist[i].prev = i - 1;
			
		}
		
		if(i == dll->count -1) {
			dll->nodelist[i].next = -1;	//last element does not have a next
			
		} else{
			dll->nodelist[i].next = i + 1;
			
		}
	}
	
	//update head and tail
	if(dll->count > 0){
		dll->head = 0;
		dll->tail = dll->count - 1;
	}
	
}

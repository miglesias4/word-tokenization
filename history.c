
#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/*
Matthew Iglesias
CS 3432 - Lab 1
Eric Freudenthal
Spring 2019

*/

/* Initialize the linked list to keep the history. */
List *init_history(void){
    List *list = NULL;
    list = malloc(sizeof(List));
    
    Item *item = NULL;
    item = malloc(sizeof(Item));
    
    list -> root = item; //assign new list root to new item
    item->id = 0;
    item->str = "";
    item->next = NULL;
    return list;
}

/* Add a history item to the end of the list.
 List* list - the linked list
 char* str - the string to store
 */
void add_history(List *list, char *string){
    Item *node = list->root;
    int idcount = 0;
    
    if(node== NULL){
        node = malloc(sizeof(Item));
        node->id = 0;
        node->str = string;
        node-> next = NULL;
        
        
    }
    else{
        while(node->next!=NULL){
            node = node->next;
            idcount+=1;
        }
        node->next = malloc(sizeof(Item));
        node->next->str = string;
        node->next->next = NULL;
        node->next->id = idcount;
    }

}

/* Retrieve the string stored in the node where Item->id == id.
 List* list - the linked list
 int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *node = list -> root;
    char *info = "";
  
    
    while(node!= NULL){
        if(node->id ==id){
            info= node->str;
            return info;
        }
    node = node->next;
    }
    
    return info;
}

/* Print the entire contents of the list. */
void print_history(List* node){
    Item *curr = node->root; //create current node for travsersal
    while(curr != NULL){ //traverse
        printf("%d: %s \n", curr->id, curr->str); //print each node and its ID
        curr = curr->next;
    }
}
void free_history(List* list){
    Item *node = list -> root;
    Item *temp;
    while(node!=NULL){
        temp = node;
        free(temp);
        node = node->next;
    }
    printf("History Free!\n");
}



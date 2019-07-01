#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next;
} t_node;


t_node* new_node(void* data);


typedef struct list {
    t_node* head;
    t_node* tail;

    int length;


} t_list;


t_list* new_list();


/*

funções tipadas pra lista:
    comparar
    to_str
    

*/

#endif

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* data;
    struct node* next;
} t_node;


t_node* create_node(void* data);


typedef struct list {
    t_node* head;
    t_node* tail;

    int length;
} t_list;


t_list* create_list();

int is_empty(t_list* list);


void insert_front(t_list* list, void* data);

void* remove_head(t_list* list);

void clear(t_list* list);
/*

funções tipadas pra lista:
    comparar
    to_str


*/

#endif

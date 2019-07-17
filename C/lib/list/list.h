#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* data;
    struct node* next;
} t_node;

t_node* create_node(void* data);


typedef struct list_t {
    t_node* head;
    t_node* tail;

    void (*print)(struct list_t* list);

    int length;
} t_list;


t_list* create_list(void (*print)(t_list* list));


int is_empty(t_list* list);

void print_str_list(t_list* list);

void print_int_list(t_list* list);

void print(t_list* list);

void insert_head(t_list* list, void* data);


void* remove_head(t_list* list);


void clear(t_list* list);



/*

funções tipadas pra lista:
    comparar
    to_str


*/

#endif

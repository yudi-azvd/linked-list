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

    int length;

    void (*print)(struct list_t* list);

} t_list;

t_list* create_list(void (*print)(t_list* list));

void* get_head(t_list* list);

void* get_tail(t_list* list);

int is_empty(t_list* list);

void print(t_list* list);

void insert_head(t_list* list, void* data);

void insert_tail(t_list* list, void* data);

void* remove_head(t_list* list);

void delete_head(t_list* list);

void clear(t_list* list);

void soft_clear(t_list* list);



/* funções tipadas para listas */
void print_str_list(t_list* list);

void print_int_list(t_list* list);


/*=============================================>>>>>
= STACK =
===============================================>>>>>*/
typedef t_list t_stack;

void push(t_stack* stack, void* data);

void pop(t_stack* stack);

void* soft_pop(t_stack* stack);

void* peek(t_stack* stack);

/*= End of STACK =*/
/*=============================================<<<<<*/


#endif

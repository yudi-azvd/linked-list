#include "list.h"

t_node* new_node(void* data) {
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->data = data;
    return node;
}


t_list* new_list() {
    t_list* list = (t_list*) malloc(sizeof(t_list));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    
    return list;
}

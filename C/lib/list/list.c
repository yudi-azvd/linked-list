#include "list.h"

t_node* create_node(void* data) {
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->data = data;
    return node;
}


t_list* create_list() {
    t_list* list = (t_list*) malloc(sizeof(t_list));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}


void insert_front(t_list* list, void* data) {
    t_node* new_node = create_node(data);

    list->length++;
    if(list->head == NULL && list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = list->head->next;
        list->head->next = new_node;
    }
}


// fazer retornar data ou o node.
void* remove_head(t_list* list) {

    if (list->head == NULL) {
        return NULL;
    }
    else {
        // removed?
        t_node* to_remove = list->head;
        list->head = list->head->next;
        free(to_remove);

        if (list->head == NULL) {
            list->tail == NULL;
        }

        list->length--;
    }
}


// void clear(t_list* list) {
//     t_node* curr_node = list->head;
//
//     while(list->head != NULL) {
//         free(curr_node);
//         curr_node = curr_node->next;
//     }
//
//     list->head = NULL;
//     list->tail = NULL;
// }

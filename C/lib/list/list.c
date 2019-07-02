#include "list.h"

/*
    malloc não zera os bytes da espaço de memória alocado.
    Por isso calloc é usado no lugar de malloc.
*/

t_node* create_node(void* data) {
    t_node* node = (t_node*) calloc(sizeof(t_node), 1);
    node->data = data;
    return node;
}


t_list* create_list() {
    t_list* list = (t_list*) calloc(sizeof(t_list), 1);

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}


int is_empty(t_list* list) {
    return (( list->head == NULL) && (list->head == list->tail));
}


// retornar o nó?
void insert_front(t_list* list, void* data) {
    if (list == NULL || data == NULL)
        return;

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
    if (list == NULL || list->head == NULL)
        return NULL;

    // removed?
    t_node* to_remove = list->head;
    void* data = to_remove->data;
    list->head = list->head->next;
    free(to_remove);

    if (list->head == NULL) {
        list->tail == NULL;
        printf("ptr %p\n", list->tail);
    }

    list->length--;
    return data;
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

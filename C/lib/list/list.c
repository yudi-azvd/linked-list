#include "list.h"

/*
    malloc não zera os bytes da espaço de memória alocado.
    Por isso calloc é usado no lugar de malloc.
*/

t_node* create_node(void* data) {
    t_node* node = (t_node*) calloc(sizeof(t_node), 1);
    node->data = data;
    node->next = NULL;
    return node;
}


t_list* create_list(void (*print)(t_list* list)) {
    t_list* list = (t_list*) calloc(sizeof(t_list), 1);

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    list->print = print;

    return list;
}

// ainda não é bem o que eu queria
// eu devia chmar uma função genérica.
// é uma cópia do ponteiro list->head
// funções privadas em C: https://stackoverflow.com/questions/1401781/how-to-implement-a-private-restricted-function-in-c
// Para fins de depuração
void print_str_list(t_list* list) {
    t_node* curr_node = list->head;
    printf("str_list:");
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("\"%s\" ", (char*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
    printf("\n");
}


void print_int_list(t_list* list) {
    t_node* curr_node = list->head;
    printf("int_list:");
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("%d ", *(int*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
    printf("\n");
}

void print(t_list* list) {
    list->print(list);
}


int is_empty(t_list* list) {
    return ((list->head == NULL) && (list->head == list->tail));
}


// retornar o nó?
void insert_front(t_list* list, void* data) {
    if (list == NULL || data == NULL)
        return;

    t_node* new_node = create_node(data);

    list->length++;
    if(list->head == NULL && list->tail == NULL) {
        list->head = new_node;
        // list->tail = new_node;
        list->tail = list->head;
        printf("insrtfrnt l->t: %p\n", list->tail);
        printf("new_node->next: %p\n", new_node->next);
        printf("insrtfrnt l->t->n: %p\n", list->tail->next);
    }
    else {
        new_node->next = list->head;
        list->head = new_node;
        // list->head->next = new_node;
    }
    printf("insrtfrnt l->t: %p\n", list->tail);
}


// fazer retornar data ou o node.
void* remove_head(t_list* list) {
    // list->head = NULL;
    printf("list->head %p\n", (list->head));
    if (list == NULL || list->head == NULL)
        return NULL;

    // removed?
    t_node* to_remove = list->head;
    void* data = to_remove->data;
    list->head = list->head->next;
    free(to_remove);

    if (list->head == NULL) {
        list->tail == NULL;
        printf("&(list->tail) %p\n", &(list->tail));
        printf("list->tail %p\n", (list->tail));
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

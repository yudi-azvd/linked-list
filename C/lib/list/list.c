#include "list.h"

/*
    malloc não zera os bytes da espaço de memória alocado.
    Por isso calloc é usado no lugar de malloc.
*/

t_node* create_node(void* data) {
    t_node* node = (t_node*) calloc(1, sizeof(t_node));
    node->data = data;
    node->next = NULL;
    return node;
}


t_list* create_list(void (*print)(t_list* list)) {
    t_list* list = (t_list*) calloc(1, sizeof(t_list));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    list->print = print;
    /* list->compare = compare; */

    return list;
}



void print(t_list* list) {
    list->print(list);
}


int is_empty(t_list* list) {
    return ( list == NULL
        || ((list->head == NULL)
         && (list->tail == NULL) ));
}


/* retornar o nó? */
void insert_head(t_list* list, void* data) {
    if (list == NULL || data == NULL)
        return;

    t_node* new_node = create_node(data);

    list->length++;
    if(list->head == NULL && list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

void insert_tail(t_list* list, void* data) {
    if (list == NULL || data == NULL)
        return;

    /*
    t_node* new_node = create_node(data);
    */

    list->length++;


}

/*
quem chama essa função dever ser o reposnsável por
liberar memória apontada por data */
void* remove_head(t_list* list) {
    if (list == NULL || list->head == NULL)
        return NULL;

    t_node* to_remove = list->head;
    void* data = to_remove->data;
    list->head = list->head->next;
    free(to_remove);

    if (list->head == NULL)
        /* Fiquei um tempão pq a linha seguinte tava assim:
        list->tail == NULL; */
        list->tail = NULL;

    list->length--;
    return data;
}


void delete_head(t_list* list) {
    void* data = remove_head(list);
    free(data);
}


void clear(t_list* list) {
    while(!is_empty(list))
        delete_head(list);
}




/**
 ainda não é bem o que eu queria
 eu devia chmar uma função genérica.
 é uma cópia do ponteiro list->head
 funções privadas em C: https://stackoverflow.com/questions/1401781/how-to-implement-a-private-restricted-function-in-c
 Para fins de depuração
 */
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
    printf("int_list: ");
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("%d ", *(int*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
    printf("\n");
}

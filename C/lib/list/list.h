
/**
 * @file 		list.h
 *
 * @author     	Yudi Yamane de Azevedo
 *
 * @date        9 Sep 2019
 *
 * @brief      	Definição do tipo list_t e suas funções.
 *
 * É uma pequena lista de operações em listas.
 * Inspirada em https://github.com/DevonCrawford/Video-Editing-Automation/blob/master/include/LinkedListAPI.h
 */


#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief      Nó com ponteiro para dado genérico.
 *
 */
typedef struct node_t {
    void* data;			/**< Ponteiro para um tipo de dado genérico. */
    struct node_t* next;	/**< Ponteiro para o próximo nó. */
} t_node;


/**
 * @brief      Cria um nó dinamicamente.
 *
 * @param      data  Ponteiro para um tipo de dado genérico.
 *
 * @return     Ponteiro para o eapço alocado.
 */
t_node* create_node(void* data);


/**
 * @brief      Lista simplesmente lincada.
 *
 */
typedef struct list_t {
    t_node* head;	/**< Ponteiro para o primeiro item. */
    t_node* tail;	/**< Ponteiro para o último item. */

    int length;

    void (*print)(struct list_t* list);	/** Ponteiro para função de imprimir */

} t_list;


/**
 * @brief      Cria dinamicamente uma lista. Quem chama
 * essa função deve liberar o espaço depois de usá-lo.
 *
 * @param[in]  print  Função responsável por imprimir a
 * lista na tela. Deve ser fornecida pelo usuário. Para
 * novos tipos de dados, o usuário deve também criar essa
 * função.
 *
 * @return     Ponteiro para a lista criada dinamicamente.
 */
t_list* create_list(void (*print)(t_list* list));

/**
 * @brief      Retorna
 *
 * @param      list  The list
 *
 * @return     The head.
 */
void* get_head(t_list* list);


/**
 * @brief      Gets the tail.
 *
 * @param      list  The list
 *
 * @return     The tail.
 */
void* get_tail(t_list* list);


/**
 * @brief      Determines if empty.
 *
 * @param      list  The list
 *
 * @return     True if empty, False otherwise.
 */
int is_empty(t_list* list);


/**
 * @brief      Imprime a lista
 *
 * @param      list  The list
 */
void print(t_list* list);


/**
 * @brief      { function_description }
 *
 * @param      list  The list
 * @param      data  The data
 */
void insert_head(t_list* list, void* data);


/**
 * @brief      { function_description }
 *
 * @param      list  The list
 * @param      data  The data
 */
void insert_tail(t_list* list, void* data);


/* quem chama essa função dever ser o reponsável por
liberar memória apontada por data */
/**
 * @brief      Removes a head.
 *
 * @param      list  The list
 *
 * @return     { description_of_the_return_value }
 */
void* remove_head(t_list* list);

void delete_head(t_list* list);

void clear(t_list* list);

void soft_clear(t_list* list);



/* funções tipadas para listas */
/**
 ainda não é bem o que eu queria
 eu devia chmar uma função genérica.
 é uma cópia do ponteiro list->head
 funções privadas em C: https://stackoverflow.com/questions/1401781/how-to-implement-a-private-restricted-function-in-c
 Para fins de depuração
 */

/**
 * @brief      { function_description }
 *
 * @param      list  The list
 */
void print_str_list(t_list* list);

void print_int_list(t_list* list);


/**
 * Definição de Stack
 *
 */
typedef t_list t_stack;

void push(t_stack* stack, void* data);

void pop(t_stack* stack);

void* soft_pop(t_stack* stack);

void* peek(t_stack* stack);


#endif

/* 
 * File:   queue.h
 * Author: jonas
 *
 * Created on April 14, 2013, 3:36 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

/* ********** ESTRUTURA DA FILA **********
 *
 * queue_begin                     queue_end
 *   |__|_| -> |__|_| -> |__|_| -> |__|/|
 *
 *  onde |__|_| e' |info|*next_node|
 *
 * - insere-se em queue_end (final da fila)
 * - remove-se de queue_begin (início da fila)
 *
 * ********* ESTRUTURA DA FILA ***********/


typedef int infotype;

/* queue_node / queue:
 * representa um nodo de uma fila;
 * possui uma estrutura de informacao e um ponteiro
 * para o proximo nodo. */
typedef struct queue_node queue;

struct queue_node {
    infotype info;
    queue *next_node;
};


/* queue_descriptor:
 * descritor de fila;
 * queue_end e' um ponteiro para o final da fila (entrada);
 * queue_begin e' um ponteiro para o inicio da fila (saida). */
typedef struct {
    queue *queue_end;
    queue *queue_begin;
} queue_descriptor;


/* initialize_queue():
 * aloca memoria para um queue_descriptor;
 * queue_end e queue_begin sao NULL. */
queue_descriptor* initialize_queue();


/* insert_node():
 * insere info em q;
 * retorna 1 caso tenha inserido com sucesso, -1 caso contrário. */
int insert_node( queue_descriptor *q, infotype info );


/* get_node():
 * retorna o info de queue_begin de q;
 * ELIMINA queue_begin de q;
 * a estrutura retornada será NULL se a fila estiver vazia. */
infotype get_node( queue_descriptor *q );


/* remove_node() :
 * elimina o queue_begin de q;
 * retorna 1 caso tenha removido com sucesso, -1 caso contrário */
int remove_node( queue_descriptor *q );


/* destroy_queue():
 * desaloca o descritor q e toda a fila da memória. */
void destroy_queue( queue_descriptor **q );


/* is_empty():
 */
int is_empty( queue_descriptor *q );

#endif	/* QUEUE_H */


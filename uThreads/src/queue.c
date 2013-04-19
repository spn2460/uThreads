#include "../lib/queue.h"
#include <stdlib.h>

queue_descriptor* initialize_queue() {

    queue_descriptor *q = (queue_descriptor *) malloc(sizeof(queue_descriptor));

    if( q != NULL ) {
        q->queue_end = NULL;
        q->queue_begin = NULL;
    }

    return q;
}

int insert_node( queue_descriptor *q, infotype info ) {

    queue *new_node;

    if( q != NULL ) {
        new_node = (queue *) malloc(sizeof(queue));
        new_node->info = info;
        new_node->next_node = NULL;

        if( is_empty(q) )
            q->queue_begin = new_node;
        else
            q->queue_end->next_node = new_node;

        q->queue_end = new_node;

        return 1;
    }
    else
        return -1;
}

infotype get_node( queue_descriptor *q ) {
    if( is_empty(q) )
        return (infotype) NULL;
    else {
        infotype info = q->queue_begin->info;
        remove_node(q);
        return info;
    }
}

int remove_node( queue_descriptor *q ) {

    queue *aux_q;

    if( q != NULL ) {
        if( !is_empty(q) ) {
            aux_q = q->queue_begin;
            q->queue_begin = q->queue_begin->next_node;
            free( aux_q );

            if( is_empty(q) ) // se a lista possuia apenas um nodo, removeu o último nodo
                q->queue_end = NULL;

            return 1;
        }
        else // se q está vazia
            return -1;
    }
    else // se q é NULL
        return -1;
}

void destroy_queue( queue_descriptor **q ) {
    queue *aux_q;

    if( *q != NULL ) {

        while( !is_empty(*q) ) {
            aux_q = (*q)->queue_begin;
            (*q)->queue_begin = (*q)->queue_begin->next_node;
            free(aux_q);
        }

        free(*q);
        *q = NULL;
    }
}

int is_empty( queue_descriptor *q ) {
    return( (q == NULL) || (q->queue_begin == NULL) );
}

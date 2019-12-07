
#ifndef _CIRMULATE_QUEUE_H_
#define _CIRMULATE_QUEUE_H_

#define CIR_QUEUE_MAX_SIZE 100
typedef int CIR_QUEUE_NODE_TYPE;


typedef struct CirQueue {
	int front;
	int rear;
	CIR_QUEUE_NODE_TYPE *data;
}CirQueue;

bool init_cir_queue(CirQueue &Q);
bool is_cirqueue_empty(CirQueue Q);
bool is_cirqueue_full(CirQueue Q);

bool push_cirqueue_node(CirQueue &Q, CIR_QUEUE_NODE_TYPE node);
bool pop_cirqueue_node(CirQueue &Q, CIR_QUEUE_NODE_TYPE &node);
bool get_cirqueue_front_node(CirQueue Q, CIR_QUEUE_NODE_TYPE &node);

int get_cirqueue_length(CirQueue Q);


#endif 


#include "stdlib.h"
#include "memory.h"
#include "CirQueue.h"


/*
* args: Q: Cir-Queue reference
* func: initilize queue, create memory space
* rets: true/false, if it is successful to initilize
*/
bool init_cir_queue(CirQueue & Q)
{
	Q.data = (CIR_QUEUE_NODE_TYPE*)malloc(CIR_QUEUE_MAX_SIZE * sizeof(CIR_QUEUE_NODE_TYPE));
	if (!Q.data)
		return false;
	Q.rear = Q.front = 0;
	return true;
}

/*
* args: Q: Cir-Queue
* func: judge queue is empty?
* rets: true, if it is empty, else false
*/
bool is_cirqueue_empty(CirQueue Q)
{
	return Q.rear == Q.front;
}

/*
* args: Q: Cir-Queue
* func: judge queue is full?
* rets: true, if it is full, else false
*/
bool is_cirqueue_full(CirQueue Q)
{
	return (Q.rear + 1) % CIR_QUEUE_MAX_SIZE == Q.front;
}

/*
* args: Q: Cir-Queue reference
        node: node, which need to push into queue
* func: push one node into queue
* rets: true, if queue is not full, else false
*/
bool push_cirqueue_node(CirQueue & Q, CIR_QUEUE_NODE_TYPE node)
{
	if (is_cirqueue_full(Q))
		return false;
	*(Q.data + Q.rear) = node;
	Q.rear = (Q.rear + 1) % CIR_QUEUE_MAX_SIZE;
	return true;
}

/*
* args: Q: Cir-Queue reference
		node: node reference, which need to push into queue
* func: pop one node from queue
* rets: true, if queue is not empty, else false
*/
bool pop_cirqueue_node(CirQueue & Q, CIR_QUEUE_NODE_TYPE & node)
{
	if (is_cirqueue_empty(Q))
		return false;
	node = *(Q.data + Q.front);
	Q.front = (Q.front + 1) % CIR_QUEUE_MAX_SIZE;
	return true;
}

/*
* args: Q: Cir-Queue
        node: node reference, which need to passing by front node
* func: get queue front node pass to node arg
* rets: true, if queue is not empty, else false
*/
bool get_cirqueue_front_node(CirQueue Q, CIR_QUEUE_NODE_TYPE & node)
{
	if (is_cirqueue_empty(Q))
		return false;
	node = *(Q.data + Q.front);
	return true;
}

/*
* args: Q: Cir-Queue
* func: get queue length or number of nodes
* rets: length of queue/nodes
*/
int get_cirqueue_length(CirQueue Q)
{
	return (Q.rear - Q.front + CIR_QUEUE_MAX_SIZE) % CIR_QUEUE_MAX_SIZE;
}


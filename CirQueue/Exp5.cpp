#include "stdio.h"
#include "CirQueue.h"


int main()
{
	CirQueue queue;
	if (!init_cir_queue(queue))
		return 0;

	for (int i = 0; i < 10; i++) 
		push_cirqueue_node(queue, i);

	CIR_QUEUE_NODE_TYPE node;
	while (!is_cirqueue_empty(queue)) {
		pop_cirqueue_node(queue, node);
		printf(" %d ", node);
	}
	printf("\n\n");
	return 0;
}


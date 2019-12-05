#include "stdlib.h"
#include "memory.h"
#include "SeqStack.h"


/*
* args: S: Seq-Stack reference
* func: initilize Seq-Stack
* rets: true/false, if it is successful to initilize stack
*/
bool init_seq_stack(SeqStack & S)
{
	S.base = (SEQ_STACK_NODE_TYPE*)malloc(SEQ_STACK_INIT_SIZE*sizeof(SEQ_STACK_NODE_TYPE));
	if (!S.base)
		return false;
	S.top = S.base;
	S.stack_size = SEQ_STACK_INIT_SIZE;
	return true;
}

/*
* args: S: Seq-Stack
* func: judge Seq-Stack is empty?
* rets: true, if Seq-Stack is empty, else false
*/
bool is_seqstack_empty(SeqStack S)
{
	return S.top == S.base;
}

/*
* args: S: Seq-Stack
* func: judge Seq-Stack is full?
* rets: true, if Seq-Stack is full, else false
*/
bool is_seqstack_full(SeqStack S)
{
	return (S.top - S.base) >= S.stack_size;
}

/*
* args: S: Seq-Stack reference
        node: node, which need to push into stack
* func: push one one into stack
* rets: true/false, if it is successful to push node into stack
*/
bool push_seqstack_node(SeqStack &S, SEQ_STACK_NODE_TYPE node)
{
	if (is_seqstack_full(S)) {
		S.base = (SEQ_STACK_NODE_TYPE*)realloc(S.base, (S.stack_size + SEQ_STACK_INCRESE_SIZE) * sizeof(SEQ_STACK_NODE_TYPE));
		if (!S.base)
			return false;
		S.top = S.top + S.stack_size;
		S.stack_size = S.stack_size + SEQ_STACK_INCRESE_SIZE;
	}
	*(S.top++) = node;
	return true;
}

/*
* args: S: Seq-Stack reference
        node: node reference, which passing by pop node
* func: pop one node from stack
* rects: true, if stack is not empty, else false
*/
bool pop_seqstack_node(SeqStack & S, SEQ_STACK_NODE_TYPE & node)
{
	if (is_seqstack_empty(S))
		return false;
	node = *(--S.top);
	return true;
}

/*
* args: S: Seq-Stack
        top_node: node reference arg, which passing by top node
* func: get top node from stack
* rets: true, if stack is not empty, else false
*/
bool get_seqstack_top(SeqStack S, SEQ_STACK_NODE_TYPE & top_node)
{
	if (is_seqstack_empty(S))
		return false;
	top_node = *(S.top - 1);
	return true;
}

/*
* args: S: Seq-Stack
* func: get stack length or number of nodes
* rets: stack length/number of nodes
*/
long int get_seqstack_length(SeqStack S)
{
	return S.top - S.base;
}


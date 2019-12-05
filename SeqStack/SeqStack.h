
#ifndef _SEQUENCE_STACK_H_
#define _SEQUENCE_STACK_H_

#define SEQ_STACK_INIT_SIZE 100
#define SEQ_STACK_INCRESE_SIZE 10

#include <string>
#include <iostream>

typedef std::string SEQ_STACK_NODE_TYPE;

typedef struct SeqStack {
	SEQ_STACK_NODE_TYPE *base;
	SEQ_STACK_NODE_TYPE *top;
	long int stack_size;
}SeqStack;


bool init_seq_stack(SeqStack &S);

bool is_seqstack_empty(SeqStack S);
bool is_seqstack_full(SeqStack S);

bool push_seqstack_node(SeqStack &S, SEQ_STACK_NODE_TYPE node);
bool pop_seqstack_node(SeqStack &S, SEQ_STACK_NODE_TYPE &node);
bool get_seqstack_top(SeqStack S, SEQ_STACK_NODE_TYPE &top_node);

long int get_seqstack_length(SeqStack S);


#endif 

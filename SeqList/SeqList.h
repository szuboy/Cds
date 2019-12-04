/*
* func:    Squence List by C++
* time:    2019-11-30
* author:  Jeremy.Zhang
* Logical: a1, a2, a3, ..., an
*/


#ifndef _SEQ_LIST_H_
#define _SEG_LIST_H_

#include "stdlib.h"

#define SEQ_LIST_INIT_SIZE 100
#define SEQ_LIST_INCRESE_SIZE 10
typedef int SEQ_LIST_NODE_TYPE;

typedef struct SeqList
{
	SEQ_LIST_NODE_TYPE *base;
	long int length;
	long int list_size;
}SeqList;

bool init_seq_list(SeqList &L);
bool is_seqlist_empty(SeqList &L);
bool insert_seqlist_node(SeqList &L, long int loc, SEQ_LIST_NODE_TYPE node);
bool delete_seqlist_node(SeqList &L, long int loc, SEQ_LIST_NODE_TYPE &node);

long int get_seqlist_length(SeqList &L);
long int get_seqlist_node_locate(SeqList &L, SEQ_LIST_NODE_TYPE node);

bool get_seqlist_node(SeqList &L, long int loc, SEQ_LIST_NODE_TYPE &node);
bool get_seqlist_next_node(SeqList &L, SEQ_LIST_NODE_TYPE cur_node, SEQ_LIST_NODE_TYPE &next_node);
bool get_seqlist_prior_node(SeqList &L, SEQ_LIST_NODE_TYPE cur_node, SEQ_LIST_NODE_TYPE &prior_node);

#endif


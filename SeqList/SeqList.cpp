#include "memory.h"
#include "stdlib.h"
#include "SeqList.h"


/*
* args: L: Seq-List reference
* func: initilize Seq-List
* rets: true/false£¬if it is successful to initilize
*/
bool init_seq_list(SeqList & L)
{
	L.base = (SEQ_LIST_NODE_TYPE*)malloc(SEQ_LIST_INIT_SIZE * sizeof(SEQ_LIST_NODE_TYPE));
	if (!L.base)
		return false;
	L.length = 0;
	L.list_size = SEQ_LIST_INIT_SIZE;
	return true;
}

/*
* args: 
      L: Seq-List reference
* func:judge Seq-List is empty?
* rets: true/false, if Seq-List is empty?
*/
bool is_seqlist_empty(SeqList & L)
{
	return 0 == L.length;
}

/*
* args: L: Seq-List reference
	    loc: node insert location
	    node: insert node
* func: insert one node to Seq-List
* rets: true/false, if it is successful to insert one node to Seq-List
*/
bool insert_seqlist_node(SeqList & L, long int loc, SEQ_LIST_NODE_TYPE node)
{
	if (loc < 1 || loc > L.length + 1)
		return false;
	if (L.length >= L.list_size){
		SEQ_LIST_NODE_TYPE *new_base = (SEQ_LIST_NODE_TYPE*)realloc(L.base, (L.list_size + SEQ_LIST_INCRESE_SIZE) * sizeof(SEQ_LIST_NODE_TYPE));
		if (!new_base)
			return false;
		L.base = new_base;
		L.list_size = L.list_size + SEQ_LIST_INCRESE_SIZE;
	}
	
	SEQ_LIST_NODE_TYPE *insert_loc = L.base + loc - 1;
	for (SEQ_LIST_NODE_TYPE *last = L.base + L.length - 1; last >= insert_loc; --last)
		*(last + 1) = *last;
	*insert_loc = node;
	L.length = L.length + 1;
	return true;
}

/*
* args: L: Seq-List reference
        loc: node delete location
		node: reference arg, assigned by delete node
* func: delete one node in Seq-List
* rets: true/false, if it is successful to delete one node in Seq-List
*/
bool delete_seqlist_node(SeqList & L, long int loc, SEQ_LIST_NODE_TYPE &node)
{
	if (loc < 1 || loc > L.length)
		return false;

	SEQ_LIST_NODE_TYPE *delete_loc = L.base + loc - 1;
	SEQ_LIST_NODE_TYPE *last = L.base + L.length - 1;
	node = *delete_loc;
	
	for (++delete_loc; delete_loc <= last; ++delete_loc)
		*(delete_loc -1) = *delete_loc;
	L.length = L.length - 1;
	return true;
}

/*
* args: L: Seq-List reference
* func: get Seq-List length or number of nodes
* rets: Seq-List length/number of nodes
*/
long int get_seqlist_length(SeqList & L)
{
	return L.length;
}

/*
* args: L: Seq-List reference
        node: which node to find its location
* func: get node location in Seq-List
* rets: node's location, if node in Seq-List, else 0
*/
long int get_seqlist_node_locate(SeqList & L, SEQ_LIST_NODE_TYPE node)
{
	for (long int i = 0; i < L.length; i++) {
		if (*(L.base + i) == node)
			return i + 1;
	}
	return 0;
}

/*
* args: L: Seq-List reference
        loc: location of node to get
		node: reference arg, assigned by node
* func: get Seq-List's node by node's location
* rets: true/false, if location if legal
*/
bool get_seqlist_node(SeqList & L, long int loc, SEQ_LIST_NODE_TYPE & node)
{
	if (loc < 1 || loc > L.length)
		return false;
	node = *(L.base + loc - 1);
	return true;
}

/*
* args: L: Seq-List reference
        cur_node: current node
		next_node: next node, after current node by passing
* func: get next node by passing current node
* rets: true/false, if it legal get next node by current node
*/
bool get_seqlist_next_node(SeqList & L, SEQ_LIST_NODE_TYPE cur_node, SEQ_LIST_NODE_TYPE & next_node)
{
	for (long int i = 0; i < L.length - 1; i++) {
		if (*(L.base + i) == cur_node) {
			next_node = *(L.base + i + 1);
			return true;
		}
	}
	return false;
}

/*
* args: L: Seq-List reference
		cur_node: current node
		prior_node: prior node, before current node by passing
* func: get prior node by passing current node
* rets: true/false, if it legal get prior node by current node
*/
bool get_seqlist_prior_node(SeqList & L, SEQ_LIST_NODE_TYPE cur_node, SEQ_LIST_NODE_TYPE & prior_node)
{
	for (long int i = 1; i < L.length; i++) {
		if (*(L.base + i) == cur_node) {
			prior_node = *(L.base + i - 1);
			return true;
		}
	}
	return false;
}


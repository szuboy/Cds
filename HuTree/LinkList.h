#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include "BiTree.h"


typedef BiTree LINK_LIST_NODE_TYPE;


typedef struct LNode {
	LINK_LIST_NODE_TYPE *data;
	struct LNode *next;
}LinkNode, *LinkList;


bool init_link_list(LinkList &L);
bool insert_linklist_node_with_sort(LinkList &L, LINK_LIST_NODE_TYPE node);

int get_linklist_length(LinkList L);
BiTree pop_linklist_min_node(LinkList &L);

#endif 


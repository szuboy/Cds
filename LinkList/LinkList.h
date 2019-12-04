/*
* func:    Link List by C++
* time:    2019-12-01
* author:  Jeremy.Zhang
* Logical: a1 -> a2 -> a3, ..., -> an
*/

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_


typedef struct PolyNode {
	int coef;
	int exps;
}PolyNode;


typedef int LINK_LIST_NODE_TYPE;

typedef struct LNode {
	LINK_LIST_NODE_TYPE *data;
	struct LNode *next;
}LinkNode, *LinkList;


LinkList create_linklist_node(LINK_LIST_NODE_TYPE data);

bool init_link_list(LinkList &L);
bool is_linklist_empty(LinkList L);
bool insert_linklist_node(LinkList L, long int loc, LINK_LIST_NODE_TYPE node);
bool delete_linklist_node(LinkList L, long int loc, LINK_LIST_NODE_TYPE &node);

bool get_linklist_node(LinkList L, long int loc, LINK_LIST_NODE_TYPE &node);

long int get_linklist_length(LinkList L);
long int get_linklist_node_locate(LinkList L, LINK_LIST_NODE_TYPE node);


#endif

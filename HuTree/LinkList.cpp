
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "LinkList.h"


/*
* args: Link-List reference
* func: initilize list
* rets: true/false, if it is successful to initilize list
*/
bool init_link_list(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LinkNode));
	if (!L)
		return false;
	L->next = NULL;
	return true;
}

/*
* args: L: Link-List reference
        node: node, which need to insert into list with sorted
* func: insert one node into list with sorted
* rets: true/false, if it is valid
*/
bool insert_linklist_node_with_sort(LinkList &L, LINK_LIST_NODE_TYPE node)
{
	LinkList LNode = (LinkList)malloc(sizeof(LinkNode));
	LNode->data = (LINK_LIST_NODE_TYPE*)malloc(sizeof(LINK_LIST_NODE_TYPE));
	*(LNode->data) = node;
	LNode->next = NULL;

	LinkList head = L;
	while (head && head->next && *((*(LNode->data))->weight) > *((*(head->next->data))->weight))
		head = head->next;

	LNode->next = head->next;
	head->next = LNode;
	return true;
}

/*
* args: L: Link-List
* func: get link list length or number of nodes
* rets: length of list/number of nodes
*/
int get_linklist_length(LinkList L)
{
	int cnts = 0;
	for (LinkList head = L; head->next; ++cnts, head = head->next);
	return cnts;
}

/*
* args: L: Link-List reference
* rets: min weight binary tree, is list first node value
*/
BiTree pop_linklist_min_node(LinkList &L)
{
	LinkList min_node = L->next;
	L->next = min_node->next;
	return *min_node->data;
}
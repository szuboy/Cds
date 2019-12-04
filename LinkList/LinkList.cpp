#include "memory.h"
#include "stdlib.h"
#include "LinkList.h"


/*
* args: node: Link-List node pointer reference
* func: create Link-List node
* rets: Link-List type node
*/
LinkList create_linklist_node(LINK_LIST_NODE_TYPE data)
{
	LinkList node = (LinkList)malloc(sizeof(LinkNode));
	if (!node)
		return node;
	node->data = (LINK_LIST_NODE_TYPE*)malloc(sizeof(LINK_LIST_NODE_TYPE));
	*(node->data) = data;
	node->next = NULL;
	return node;
}

/*
* args: L: Link-List pointer reference
* func: initilize Link-List, create head node
* rets: true/false, if it is successful to initilize
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
* args: L: Link-List pointer
* func: judge Link-List is empty?
* rets: true/false, if it is empty?
*/
bool is_linklist_empty(LinkList L)
{
	return NULL == L->next;
}

/*
* args: L: Link-List pointer
* func: insert one node into Link-List in location by loc arg
* rets: true/false, if it is successful to insert at loc position
*/
bool insert_linklist_node(LinkList L, long int loc, LINK_LIST_NODE_TYPE node)
{
	LinkList head = L;
	long int cnts = 0;
	
	for (; head && cnts < loc - 1; ++cnts)
		head = head->next;

	if (!head || cnts > loc - 1)
		return false;

	LinkList insert_node = create_linklist_node(node);
	if (!insert_node)
		return false;

	insert_node->next = head->next;
	head->next = insert_node;

	return true;
}

/*
* args: L: Link-List pointer
        loc: deleted node location
		node: reference arg, passing by deleted node
* func: insert one node into Link-List in location by loc arg
* rets: true/false, if it is successful to delete node by loc arg
*/
bool delete_linklist_node(LinkList L, long int loc, LINK_LIST_NODE_TYPE & node)
{
	LinkList head = L;
	long int cnts = 0;

	for (; head->next && cnts < loc - 1; ++cnts)
		head = head->next;

	if (!(head->next) || cnts > loc - 1)
		return false;

	LinkList delete_node = head->next;
	head->next = delete_node->next;
	node = *delete_node->data;
	free(delete_node);
	return true;
}

/*
* args: L: Link-List pointer
        loc: node location
		node: reference arg, passing by node with loc arg
* func: get Link-List node by loc arg
* rets: true/false, if it is legal
*/
bool get_linklist_node(LinkList L, long int loc, LINK_LIST_NODE_TYPE & node)
{
	LinkList head = L->next;
	
	for (long int cnts = 1; head; ++cnts, head = head->next)
		if (cnts == loc)
			node = *(head->data);
	if (!head)
		return false;
	return true;
}

/*
* args: L: Link-List pointer
* func: get Link-List length or number of nodes
* rets: Link-List length or number of nodes
*/
long int get_linklist_length(LinkList L)
{
	LinkList head = L;
	long int cnts = 0;
	
	for (; head->next; ++cnts)
		head = head->next;

	return cnts;
}

/*
* args: L: Link-List pointer
		node: which node to find its location
* func: get node location in Seq-List
* rets: node's location, if node in Seq-List, else 0
*/
long int get_linklist_node_locate(LinkList L, LINK_LIST_NODE_TYPE node)
{
	LinkList head = L;
	for (long int cnts = 1; head->next; ++cnts, head=head->next)
		if (*head->data == node)
			return cnts;
	return 0;
}

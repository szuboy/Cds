#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "BiTree.h"



static void create_binary_tree_node(BiTree &T, BINARY_TREE_NODE_TYPE *nodes, int &index)
{
	
	if (*(nodes + index) == '@')
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = *(nodes + index);
		create_binary_tree_node(T->lchild, nodes, index = index + 1);
		create_binary_tree_node(T->rchild, nodes, index = index + 1);
	}
}


/*
* args: T: BiTree reference
        nodes: nodes, which to build binary tree
* func: build tree base preorder
* rets: none
*/
void create_binary_tree_base_preorder(BiTree &T, BINARY_TREE_NODE_TYPE * nodes)
{
	int index = 0;
	create_binary_tree_node(T, nodes, index);
}

/*
* args: T: BiTree
* func: traval tree base preorder
* rets: none
*/
void traval_binary_tree_base_preorder(BiTree T)
{
	if (!T)
		printf("@");
	else {
		printf("%c", T->data);
		traval_binary_tree_base_preorder(T->lchild);
		traval_binary_tree_base_preorder(T->rchild);
	}
}

/*
* args: T: BiTree
* func: traval tree base inorder
* rets: none
*/
void traval_binary_tree_base_inorder(BiTree T)
{
	if (!T)
		printf("@");
	else {
		traval_binary_tree_base_inorder(T->lchild);
		printf("%c", T->data);
		traval_binary_tree_base_inorder(T->rchild);
	}
}

/*
* args: T: BiTree
* func: traval tree base postorder
* rets: none
*/
void traval_binary_tree_base_postorder(BiTree T)
{
	if (!T)
		printf("@");
	else {
		traval_binary_tree_base_postorder(T->lchild);
		traval_binary_tree_base_postorder(T->rchild);
		printf("%c", T->data);
	}
}

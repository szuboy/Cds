
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "BiTree.h"


/*
* args: weight: node weight
* func: create binary tree node, passing by weight arg
* rets: binary tree, with lchild and rchild is null
*/
BiTree create_binary_tree_node(BINARY_TREE_NODE_TYPE weight)
{
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	T->weight = (BINARY_TREE_NODE_TYPE*)malloc(sizeof(BINARY_TREE_NODE_TYPE));
	*(T->weight) = weight;
	T->lchild = T->rchild = NULL;
	return T;
}

/*
* args: T1: binary tree T2
        T2: binary tree T2
* func: combine T1 and T2 as T's lchild and rchild
* rets: T[:binary tree, combine T1 and T2
*/
BiTree combine_binary_tree_node(BiTree T1, BiTree T2)
{
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	T->weight = (BINARY_TREE_NODE_TYPE*)malloc(sizeof(BINARY_TREE_NODE_TYPE));
	*(T->weight) = *(T1->weight) + *(T2->weight);
	T->lchild = T1;
	T->rchild = T2;
	return T;
}


/*
* args: T: BiTree
* func: traval tree base inorder
* rets: none
*/
void traval_binary_tree_base_inorder(BiTree T)
{
	if (!T)
		return;
	else {
		traval_binary_tree_base_inorder(T->lchild);
		printf("%f ", *(T->weight));
		traval_binary_tree_base_inorder(T->rchild);
	}
}
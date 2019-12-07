#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_


typedef float BINARY_TREE_NODE_TYPE;


typedef struct BiTNode {
	BINARY_TREE_NODE_TYPE *weight;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

BiTree create_binary_tree_node(BINARY_TREE_NODE_TYPE weight);
BiTree combine_binary_tree_node(BiTree T1, BiTree T2);
void traval_binary_tree_base_inorder(BiTree T);

#endif 

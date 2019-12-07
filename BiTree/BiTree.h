#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_


typedef char BINARY_TREE_NODE_TYPE;

typedef struct BiTNode {
	BINARY_TREE_NODE_TYPE data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

void create_binary_tree_base_preorder(BiTree &T, BINARY_TREE_NODE_TYPE *nodes);

void traval_binary_tree_base_preorder(BiTree T);
void traval_binary_tree_base_inorder(BiTree T);
void traval_binary_tree_base_postorder(BiTree T);


#endif


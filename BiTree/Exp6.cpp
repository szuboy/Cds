#include "stdio.h"
#include "BiTree.h"


int main()
{
	BiTree T = NULL;
	BINARY_TREE_NODE_TYPE nodes[255] = "ABC@@DE@G@@F@@@";
	create_binary_tree_base_preorder(T, nodes);

	printf("\n>>>preorder: \n");
	traval_binary_tree_base_preorder(T);

	printf("\n>>>inorder: \n");
	traval_binary_tree_base_inorder(T);

	printf("\n>>>postorder: \n");
	traval_binary_tree_base_postorder(T);

	printf("\n\n");
	return 0;
}


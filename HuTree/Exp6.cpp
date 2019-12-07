
#include "stdio.h"
#include "HuTree.h"


int main()
{
	float weight[8] = {7, 19, 2, 6, 32, 3, 21, 10};
	BiTree T = build_huffman_tree_with_weight(weight, 8);
	
	traval_binary_tree_base_inorder(T);

	return 0;
}


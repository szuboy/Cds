
#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "BiTree.h"
#include "HuTree.h"
#include "LinkList.h"


/*
* args: weight: node's weight
        n: length of weight array
* func: build huffman tree with weight
* rets: Huffman Binary Tree
*/
BiTree build_huffman_tree_with_weight(float * weight, int n)
{
	LinkList L;
	if (!init_link_list(L))
		return NULL;
	for (int i = 0; i < n; i++) {
		BiTree T = create_binary_tree_node(weight[i]);
		insert_linklist_node_with_sort(L, T);
	}

	BiTree T1, T2;
	while (get_linklist_length(L) != 1) {
		T1 = pop_linklist_min_node(L);
		T2 = pop_linklist_min_node(L);
		BiTree T = combine_binary_tree_node(T1, T2);
		insert_linklist_node_with_sort(L, T);
	}

	return *(L->next->data);
}

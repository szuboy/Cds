#include "stdio.h"
#include "SeqList.h"


bool print_seqlist_node(SeqList L)
{
	for (long int cnts = 0; cnts < L.length; ++cnts)
		printf("  %d  |", *(L.base + cnts));
	printf("\n");
	return true;
}


bool opt_seqlis_node(SeqList &L, char opt, int loc, int node)
{
	switch (opt) {
	case 'D':
		printf("loc: ");
		scanf("%d", &loc);
		delete_seqlist_node(L, loc, node);
		break;
	case 'I':
		printf("loc, node: ");
		scanf("%d %d", &loc, &node);
		insert_seqlist_node(L, loc, node);
		break;
	case 'P':
		print_seqlist_node(L);
		break;
	case 'E':
		exit(0);
		break;
	default:
		break;
	}
}


bool merge_seqlist_node(SeqList L1, SeqList L2, SeqList &L)
{
	if (!init_seq_list(L))
		return false;

	long int l1_loc = 1, l2_loc = 1, l_loc = 0;
	SEQ_LIST_NODE_TYPE l1_node, l2_node;
	
	while (l1_loc <= get_seqlist_length(L1) && l2_loc <= get_seqlist_length(L2)){
		get_seqlist_node(L1, l1_loc, l1_node);
		get_seqlist_node(L2, l2_loc, l2_node);
		if (l1_node <= l2_node) {
			insert_seqlist_node(L, ++l_loc, l1_node);
			++l1_loc;
		}
		else {
			insert_seqlist_node(L, ++l_loc, l2_node);
			++l2_node;
		}
	}

	while (l1_loc <= get_seqlist_length(L1)) {
		get_seqlist_node(L1, l1_loc++, l1_node);
		insert_seqlist_node(L, ++l_loc, l1_node);
	}
	while (l2_loc <= get_seqlist_length(L2)) {
		get_seqlist_node(L2, l2_loc++, l2_node);
		insert_seqlist_node(L, ++l_loc, l2_node);
	}

	return true;
}


int main()
{
	SeqList List;
	
	if (!init_seq_list(List))
		return 0;

	int length = 10;
	for (int i = 1; i < length; i++) {
		insert_seqlist_node(List, get_seqlist_length(List) + 1, i);
	}

	char opt;
	int node = 0, loc = 0;
	printf("Opts: Exit(E), Insert(I), Delete(D), Print(P) \n");

	while (true) {
		printf("\n>>> ");
		scanf(" %c", &opt);
		opt_seqlis_node(List, opt, loc, node);
	}

	return 0;
}
#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"




bool print_linklist_node(LinkList L)
{
	LinkList head = L->next;
	for (; head; head=head->next)
		printf("  %d  |", *(head->data));
	printf("\n");
	return true;
}


bool opt_seqlis_node(LinkList &L, char opt, int loc, int node)
{
	switch (opt) {
	case 'D':
		printf("loc: ");
		scanf("%d", &loc);
		delete_linklist_node(L, loc, node);
		break;
	case 'I':
		printf("loc, node: ");
		scanf("%d %d", &loc, &node);
		insert_linklist_node(L, loc, node);
		break;
	case 'P':
		print_linklist_node(L);
		break;
	case 'E':
		exit(0);
		break;
	default:
		break;
	}
}


/*
bool print_poly_node(LinkList L)
{
	LinkList head = L->next;
	for (; head; head = head->next)
		printf("%+d^%d ", (head->data)->coef, (head->data)->exps);
	printf("\n\n");
	return true;
}

bool poly_add_func(LinkList poly1, LinkList poly2, LinkList &poly)
{
	LinkList p1_node = poly1->next, p2_node = poly2->next;
	long int loc = 1; PolyNode poly_node;
	while (p1_node && p2_node) {
		if (p1_node->data->exps < p2_node->data->exps) {
			insert_linklist_node(poly, loc++, *(p1_node->data));
			p1_node = p1_node->next;
		}
		if (p1_node->data->exps > p2_node->data->exps) {
			insert_linklist_node(poly, loc++, *(p2_node->data));
			p2_node = p2_node->next;
		}
		if (p1_node->data->exps == p2_node->data->exps) {
			poly_node.coef = p1_node->data->coef + p2_node->data->coef;
			poly_node.exps = p1_node->data->exps;
			insert_linklist_node(poly, loc++, poly_node);
			p1_node = p1_node->next; p2_node = p2_node->next;
		}
	}
	while (p1_node) {
		insert_linklist_node(poly, loc++, *(p1_node->data));
		p1_node = p1_node->next;
	}
	while (p2_node) {
		insert_linklist_node(poly, loc++, *(p2_node->data));
		p2_node = p2_node->next;
	}
	return true;
}
*/


int main()
{
	
	LinkList linkList;
	if (!init_link_list(linkList))
		return 0;

	int length = 10;
	for (int i = 1; i < length; i++) {
		insert_linklist_node(linkList, get_linklist_length(linkList) + 1, i);
	}

	char opt;
	int node = 0, loc = 0;
	printf("Opts: Exit(E), Insert(I), Delete(D), Print(P) \n");

	while (true) {
		printf("\n>>> ");
		scanf(" %c", &opt);
		opt_seqlis_node(linkList, opt, loc, node);
	}

	return 0;
	
	/*
	LinkList poly1, poly2, poly;
	if (!init_link_list(poly1) || !init_link_list(poly2) || !init_link_list(poly))
		return 0;
	
	PolyNode poly1_node, poly2_node;
	for (int exps = -1, loc = 1; exps < 5; ++exps, ++loc) {
		poly1_node.coef = poly1_node.exps = exps;
		insert_linklist_node(poly1, loc, poly1_node);

		poly2_node.coef = 2 * exps; poly2_node.exps = exps + 2;
		insert_linklist_node(poly2, loc, poly2_node);
	}

	printf(">>>poly: \n");
	print_poly_node(poly1);
	
	printf(">>>poly: \n");
	print_poly_node(poly2);

	printf(">>>rets: \n");
	poly_add_func(poly1, poly2, poly);
	print_poly_node(poly);
	*/
}


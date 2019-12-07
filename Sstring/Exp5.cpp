#include "stdio.h"
#include "Sstring.h"


int main()
{
	Sstring S = { 9, 'a', 'b', 'a', 'b', 'a', 'd', 'a', 'a', 'b' };
	Sstring T = { 4, 'a', 'b', 'a', 'd' };

	int general_index = find_Sstring_index_base_general(S, T, 1);
	int KMP_index = find_Sstring_index_base_KMP(S, T, 1);
	printf("general_index: %d  \n\nKMP_index: %d \n\n", general_index, KMP_index);
	
	return 0;
}


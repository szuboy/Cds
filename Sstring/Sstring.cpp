#include "stdlib.h"
#include "memory.h"
#include "Sstring.h"
#include "stdio.h"

/*
* args: S: string, to be matched
        T: pattern string
		pos: where in the S to be match
* func: string pattern match
* rets: T first position in T
*/
int find_Sstring_index_base_general(Sstring S, Sstring T, int pos)
{
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j])
			++i, ++j;
		else
			i = i - j + 2, j = 1;
	}
	if (j > T[0])
		return i - T[0];
	else
	    return 0;
}

/*
* args: T: pattern string
* func: get string next array
* rets: next array
*/
static int* get_Sstring_next(Sstring T)
{
	int i = 1, j = 0;
	int *next = (int*)malloc(T[0] * sizeof(int));
	
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
	return next;
}

/*
* args: S: string, to be matched
		T: pattern string
		pos: where in the S to be match
* func: string pattern match
* rets: T first position in T
*/
int find_Sstring_index_base_KMP(Sstring S, Sstring T, int pos)
{
	int i = pos, j = 1;
	int *next = get_Sstring_next(T);

	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j])
			++i, ++j;
		else
			j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
	return 0;
}


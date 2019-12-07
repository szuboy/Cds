#ifndef _SSTRING_H_
#define _SSTRING_H_

#define SSTRING_MAX_STR_LEN 255
typedef unsigned char Sstring[SSTRING_MAX_STR_LEN + 1];

int find_Sstring_index_base_general(Sstring S, Sstring T, int pos);

int find_Sstring_index_base_KMP(Sstring S, Sstring T, int pos);

#endif


/* Word Count Header
 *
 * Tyler Mau
 * January 30, 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WORD_FACTOR 4
#define HASH_ADJ 13
#define TABLE_SIZE 500

struct wordInfo {
	char *word;
	int count;
	struct wordInfo *next;
};

void countWords(char *str);
void removeCharacters(char *str);
void toLowerCase(char *str);
void hashAdd(struct wordInfo **map, char *loc, int wordLen);
int hash(char *word, int len);

/* Counts Number of Occurances for Each Word in String
 *
 * Tyler Mau
 * January 30, 2015
 */

#include "wordcount.h"

void countWords(char *str) {
   int strLen = strlen(str) - 1, wordLen = 0, cnt;
   char *loc = str;
   struct wordInfo **hashMap = malloc(sizeof(struct wordInfo *) * TABLE_SIZE);
   struct wordInfo *temp;

   removeCharacters(str);
   toLowerCase(str);

   while (loc < str + strLen) {
      while (*loc == ' ') {
         loc++;
      }

      while (loc + wordLen < str + strLen && *(loc + wordLen) != ' ' && *(loc + wordLen) != '\n') {
         wordLen++;
      }

      if (loc < str + strLen) {
         hashAdd(hashMap, loc, wordLen);
      }

      loc += wordLen;
      wordLen = 0;
   }

   for (cnt = 0; cnt < TABLE_SIZE; cnt++) {
      temp = hashMap[cnt];
      while (temp != NULL) {
         printf("\nWord: %s\nNumber: %d\n", temp->word, temp->count);
         temp = temp->next;
      }
   }

}

void removeCharacters(char *str) {
   char *loc = str;

   while (loc < str + strlen(str)) {
      if ((*loc < 'a' && *loc > 'Z') || (*loc < 'A' ) || (*loc > 'z')) {
         *loc = ' ';
      }
      loc++;
   }
}

void toLowerCase(char *str) {
   char *loc = str;

   while (loc < str + strlen(str) - 1) {
      if (*loc != ' ' && *loc >= 'A' && *loc <= 'Z') {
         *loc += 'a' - 'A';
      }
      loc++;
   }
}

void hashAdd(struct wordInfo **map, char *loc, int wordLen) {
   struct wordInfo *elem, *temp;
   char *word = calloc(1, wordLen + 1);
   int hashValue, found = 0;

   hashValue = hash(loc, wordLen);

   if (map[hashValue] == NULL) {
      elem = malloc(sizeof(struct wordInfo));
      elem->word = calloc(1, wordLen + 1);
      strncpy(elem->word, loc, wordLen);
      elem->count = 1;
      elem->next = NULL;

      map[hashValue] = elem;
   }
   else {
      temp = map[hashValue];

      if (temp && !strncmp(temp->word, loc, wordLen)) {
         temp->count++;
         return;
      }

      while (temp && temp->next) {
         if (!strncmp(temp->next->word, loc, wordLen)) {
            temp->next->count++;
            found = 1;
         }
         temp = temp->next;
      }

      if (!found) {
         elem = malloc(sizeof(struct wordInfo));
         elem->word = calloc(1, wordLen + 1);
         strncpy(elem->word, loc, wordLen);
         elem->count = 1;
         elem->next = NULL;

         temp->next = elem;
      }
   }

}

int hash(char *word, int len) {
   int cnt, hashNum = -HASH_ADJ;

   for (cnt = 0; cnt < len; cnt++) {
      hashNum += word[cnt] - 'a' + HASH_ADJ;
   }

   return hashNum;
}

void cleanup() {

}

/* Test Driver for Word Counter
 *
 * Tyler Mau
 * January 30, 2015
 */

#include "wordcount.h"

int main () {
   char str[100];

   printf("Please Enter a String (Max 100 Characters): ");
   fgets(str, 99, stdin);

   countWords(str);

   return 0;
}

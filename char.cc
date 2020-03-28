#include<stdio.h>
#include<ctype.h>

int main() {
   char val1 = 's';
   char val2 = '8';
   
   if(isalpha(val1))
      printf("The character is an alphabet\n");
   else
      printf("The character is not an alphabet\n");
   
   if(isalpha(val2)) 
      printf("The character is an alphabet\n");
   else
      printf("The character is not an alphabet");
   
   printf("%d\n", tolower('S'));
   printf("%d\n", tolower('s'));
   return 0;
}
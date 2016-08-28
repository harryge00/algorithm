#include<stdio.h>
#include <stdlib.h>
int main() {
	char *string_a=(char *)malloc(100*sizeof(char));
	char string_b[100];
	printf("%d, %d\n", sizeof(string_a), sizeof(string_b));
	return 0;
}
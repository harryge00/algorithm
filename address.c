#include<stdio.h>
#include <stdlib.h>

int palidrome() {
	int p[1000], mx = 0, id = 0;
	memset(p, 0, sizeof(p));
	for (i = 1; s[i] != '\0'; i++) {
	    p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
	    while (s[i + p[i]] == s[i - p[i]]) p[i]++;
	    if (i + p[i] > mx) {
	        mx = i + p[i];
	        id = i;
	    }
	}
}
int main() {
	char *string_a=(char *)malloc(100*sizeof(char));
	char string_b[100];
	printf("%d, %d\n", sizeof(string_a), sizeof(string_b));
	return 0;
}
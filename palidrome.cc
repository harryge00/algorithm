#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

using namespace std;

int palidrome(char s[]) {
	int p[1000], mx = 0, id = 0, i = 0;
	int j = 0;
	memset(p, 0, sizeof(p));
	for (i = 1; s[i] != '\0'; i++) {
	    p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
	    cout << i << ":" << endl;
		cout<< s[i] << "," << p[i] << endl;
	    while (s[i + p[i]] == s[i - p[i]]) {
	    	for(j = i - p[i]; j <= i + p[i]; j++) {
	    		cout << s[j];
	    	}
	    	p[i]++;
			cout<< " p[" << i << "]" << p[i] << endl;
	    }
	    if (i + p[i] > mx) {
	        mx = i + p[i];
	        id = i;
	    }
	    cout << "id: " << id << " mx: " << mx << endl;
	}
	int result = 0;
	for(i = 0; i < 1000; i++) {
		if(p[i] > result) {
			result = p[i];
		}
	}
	return result;
}
int main() {
	char greeting[] = "1221232122122";
	cout << greeting << endl;
	printf("%d \n", palidrome(greeting));
	return 0;
}
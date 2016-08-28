#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<list>
#include<algorithm>
using namespace std;


int main()
{

 	int n;
 	cin>>n;
 	int remain = 0, max = n;
 	while(n > 0) {
 		remain = n > 3? n % 3:0;
 		n /= 3;
 		max += n;
 		n += remain;
 	}
 	cout<<max<<endl;
 	
}

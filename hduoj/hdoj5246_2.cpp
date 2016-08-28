//hdoj5246
// poj 1094 拓扑排序
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
bool waytoSort(int x, int y) {return x>y;}
string beatAll(int acmer[], int n, int m, int k) {
	
	// for(int i = 0; i < n - 1; i++) {
	// 	int max = i;
	// 	for(int j = i+1;j<n;j++)
	// 		if(acmer[max] < acmer[j]) max = j;

	// 	int tmp = acmer[i];
	// 	//cout<<acmer[max]<<" at "<<max<<endl;
	// 	acmer[i] = acmer[max];
	// 	acmer[max] = tmp;
	// }
	sort(acmer,acmer+n);
	int begin = 0, end = n-1;
	while(begin < end && ) {
		int mid = begin + end)
	}
	//for(int i = 0; i < n; i++) cout<<acmer[i] << " ";
	if(acmer[0] < m) return "why am I so diao?";
	map<int,int> kmap;
	for(int i = 0; i <= k;i++ ){
		kmap[i]=0;
	}
	int diff = acmer[0] - acmer[1];
	if(diff > k) return "Madan!";
	
	kmap[diff] = 1;
	int limit = diff;
	for(int i = 1; i < n-1; i++) {
		if(acmer[i] < m) return "why am I so diao?";
		int diff2 = acmer[i] - acmer[i+1];
		if(diff2>k || diff2 < diff && diff2!=0) return "Madan!";
		if(kmap[diff2] == 1) return "Madan!";
		else kmap[diff2] = 1;
		limit = diff2>limit?diff2:limit;
	}
	
	return "why am I so diao?";
}

int main()
{

 	int cases;
 	cin>>cases;
 	list<string> res;
 	for(int i = 0; i < cases; i++) {
 		int n,m,k;
 		cin>>n>>m>>k;
 		int acmer[10000];
 		for(int j = 0; j < n; j++) {
 			cin>>acmer[j];
 		}
 		res.push_back(beatAll(acmer,n,m,k));
 	}
 	// cin>>cases;
 	for(list<string>::iterator it = res.begin();it!=res.end();it++){
 		cout<<(*it)<<endl;
 	}
	return 0;
}

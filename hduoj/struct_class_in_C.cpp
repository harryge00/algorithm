// poj 1094 拓扑排序
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class ll {
	public:
	int val;
	ll* next;
	public:
	ll* insert(int x) {
		ll* res = this;
		if(x < val) {
			ll listnode(x);
			res =&listnode;
			(*res).next=this;
			return res;
		}
		ll *p=next, *pre=this;
		while(p!=NULL && p->val>x) {
			pre=p;
			p=p->next;
		}
		ll listnode(x,p);
		pre->next=&listnode;
		return res;
	}
	ll(int x) {
		val = x;
		next=NULL;
	}
	ll(int x, ll* pointer) {
		val=x;
		next=pointer;
	}
};

int main()
{
 	ll* root;
 	root->next=NULL;
 	int x, num = 0;
 	bool flag = true;
 	string s;
 	while(scanf("%s5", s)) {
 		cout<<s<<" ";
 		x = atoi(s);
 		
 		cout<< x<<endl;
 	}
 	ll* p = root;
 	// while(p!=NULL) {
 	// 	cout<<p->val;
 	// 	if(p->next!=NULL) cout<<" ";
 	// }
 	// cout<<endl;
	
	return 0;
}

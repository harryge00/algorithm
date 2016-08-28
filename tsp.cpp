#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<climits>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;
#define N 21
int arc[N][N];
list<int> backtrace(list<int> ans, queue<int> remain, int curr, int len, int & min);

int main()
{
	//min = INT_MAX;
 	
 	int n;
 	cin>>n;
 	for(int i = 1; i <= n; i++) {
 		for(int j = 1; j <= n; j++) {
 			cin >> arc[i][j];
 		}
 	}
 	// for(int i = 1; i <= n; i++) {
 	// 	for(int j = 1; j <= n; j++) {
 	// 		cout << arc[i][j];
 	// 	}
 	// 	cout<<endl;
 	// }

 	list<int> res;
 	queue<int> remain;
 	for(int i = 2; i<=n;i++) {
 		remain.push(i);
 	}
 	res.push_back(1);
 	int min;
 	res = backtrace(res, remain, 1, 0, min);
 	for(list<int>::iterator it = res.begin(); it != res.end(); it++) {
 		cout<<*it<<",";
	}
 	cout<<min<<endl;
 	
}

list<int> backtrace(list<int> ans, queue<int> remain, int curr, int len, int & flag) {
	//cout<<"list size: "<<ans.size()<<" curr "<<curr<<" remain:"<<remain.size()<<" len "<<len <<endl;
	if(remain.size() == 0) {
		len += arc[curr][1];
		flag = len;
		return ans;
	}

	list<int> backup, minList;
	int min = INT_MAX;
	for(int i =0;i<remain.size();i++) {
		int tmp = remain.front();
		remain.pop();
		ans.push_back(tmp);
		minList = backtrace(ans, remain, tmp, len + arc[curr][tmp], flag);
		if(flag < min) {
			min = flag;
			backup = minList;
		}
		ans.pop_back();
		remain.push(tmp);
	}
	flag = min;
	return backup;
}
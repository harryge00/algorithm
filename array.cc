#include <iostream>
#include <string>
#include <climits>

using namespace std;
int main() {
	int k = 4;
	int g[k] ={};
	g[0] = 1;
	cout<<g[0]<<","<<g[1]<<","<<g[2]<<","<<g[3]<<endl;
	string str = "(-3,5),(87,4),(93,3),(3,0)";
	cout<<str.substr(str.find('(') + 1, str.find(","));
	int [] arr = new int[10];
	cout<<arr[0]<<","<<arr[1]<<","<<arr[2]<<","<<arr[3]<<endl;
	long a = LONG_MIN;
	cout << a << endl;
	int i = 0; 
	bool f = i > a;
}
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int res = 0;
    vector<int> uglyNums(n);
    int len = primes.size();
    vector<int> index(len, 0);
    uglyNums[0] = 1;
    int next;
    for(int i=1;i<n;i++) {
    	next = INT_MAX;
    	for(int j = 0; j < index.size(); j++) {
    		if(primes[j]*uglyNums[index[j]] < next) {
    			next = primes[j]*uglyNums[index[j]];
    		}
    	}
    	uglyNums[i] = next;
    	for(int j = 0; j < index.size(); j++) {
    		if(primes[j]*uglyNums[index[j]] == next) {
    			index[j]++;
    		}
    	}
    }
    return uglyNums[n-1];
}
int main() {
	int arr[] = {2, 7, 13, 19};
	vector<int> primes(arr, arr+3);
	cout<<nthSuperUglyNumber(13, primes)<<endl;
}

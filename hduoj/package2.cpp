#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int optimum(int n, int cap, int p[], int w[]){
    int dp[1001];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = cap - w[i]; j >= 0; j--) {
            if(dp[j] + p[i] > dp[j + w[i]]) dp[j + w[i]] = dp[j] + p[i];
        }
    }
    return dp[cap];

}
int main() {
    int n, cap, tests, p[1001], w[1001];
    cin >> tests;
    for(int t = 0; t < tests; t++) {
        cin >> n >> cap;
        int i = 0;
        while(i < n) {
            cin >> p[i++];
        }
        i = 0;
        while(i < n) {
            cin >> w[i++];
        }
        cout << optimum(n, cap, p, w) << endl;
    }
}

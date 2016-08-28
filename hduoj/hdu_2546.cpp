
#include<iostream>
#include<cstdio>
#include<memory.h>

using namespace std;

#define MAXT 100010


int main()
{
    int n, dp[1100], p[1001], m;
	while(scanf("%d", &n) && n)
	{
        memset(dp, 0, sizeof(dp));
        int max = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", p + i);
        }
        scanf("%d", &m);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = m - 5; j >= 0; j--){
                if(dp[j] == 1) {
                    dp[j + p[i]] = 1;
                    if(j + p[i] > max) max = j + p[i];
                }
            }
        }
        cout << m - max <<endl;
	}
	return 0;
}

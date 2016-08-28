
#include<iostream>
#include<cstdio>
#include<memory.h>

using namespace std;

#define MAXT 100


int solve(int i, int n, int c, int weight[], int value[]) {
    if(c <= 0 || i >= n) return 0;

    if(weight[i] <= c) {
        int pick = value[i] + solve(i + 1, n, c - weight[i], weight, value);
        int noPick = solve(i + 1, n, c, weight, value);
        return pick > noPick ? pick : noPick;
    }
    else
        return solve(i + 1, c, n, weight, value);
}
int main()
{
    int n, weight[MAXT], value[MAXT], capacity;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cin >> capacity;
    cout << solve(0, n, capacity, weight, value) <<endl;
	return 0;
}

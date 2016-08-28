#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;
int a[1050],dp[1050];

int main()
{
    int n,m,max,i,j;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        scanf("%d",&m);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        max=0;
        for(i=0;i<n;i++)
            for(j=m-5;j>=0;j--)
                if(dp[j])
                {
                    dp[j+a[i]]=1;
                    if(j+a[i]>max)
                        max=j+a[i];
                }
            printf("%d\n",m-max);
    }
    return 0;
}

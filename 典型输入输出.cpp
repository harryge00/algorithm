// poj 1094 拓扑排序
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
#define N 28
int graph[N][N],indegree[N],list[N],in[N];
int toposort(int n)
{
	int i,u,j=0;  
	int multisolution=0; /*初始化*/
	stack<int>S;
	memset(list,0,sizeof(list[0]));
	memcpy(in,indegree,sizeof(in));   /*将入度数组复制，避免修改主函数里的数据引发错误*/
	for(i=0;i<n;i++)
		if(in[i]==0)
			S.push(i);  /*将所有入度为0的点入栈*/
	while(!S.empty())
	{
		if(S.size()>1)
			multisolution=1;  /*当前有多于1个入度为0的点，则拓扑序列不唯一*/
		u=S.top();
		S.pop();
		list[j++]=u;   /*记录拓扑序列*/
		for(i=0;i<n;i++)
			if(graph[u][i])
				if(--in[i]==0)
					S.push(i);   /*将入度为0的点入栈*/
	}
	if(j!=n)  /*不能拓扑排序，即有环*/
		return 1;
	else if(multisolution)   /*有多种排序方式，不能唯一确定*/
		return 2;
	return 0;  /*序列能够被唯一确定*/
}
int main()
{
	char v1,v2;
	int i,j,k,m,n,determined,inconsistency,result;
	while(scanf("%d%d",&n,&m),m!=0||n!=0)
	{
		getchar();
		memset(graph,0,sizeof(graph));
		memset(indegree,0,sizeof(indegree));  
		determined=inconsistency=0;  /*初始化*/
		for(i=1;i<=m;i++)
		{
			scanf("%c<%c",&v1,&v2);
			getchar();
			if(!determined && !inconsistency)
			{
				if(graph[v2-'A'][v1-'A']==1)  /*存在反向边，则发现矛盾*/
				{
					printf("Inconsistency found after %d relations./n",i);
					inconsistency=1;
					continue;
				}
				graph[v1-'A'][v2-'A']=1;
				indegree[v2-'A']++;
				result=toposort(n);  /*拓扑排序*/
				if(result==0)  /*序列能够被唯一确定*/
				{
					printf("Sorted sequence determined after %d relations: ",i);
					for(k=0;k<n;k++)
						printf("%c",list[k]+'A');
					printf("./n");
					determined=1;
				}
				else if(result==1)  /*不能拓扑排序，即有环，发现矛盾*/
				{
					printf("Inconsistency found after %d relations./n",i);
					inconsistency=1;
				}
			}
		}
		if(!determined && !inconsistency)  /*既没有唯一确定，也没发现矛盾（有环），即不能确定*/
			printf("Sorted sequence cannot be determined./n");
	}
	return 0;
}

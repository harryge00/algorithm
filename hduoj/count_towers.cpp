#include <iostream>
using namespace std;

int main(){
	
	int d1[6][6],d2[6][6];
	int max,result;
	for (int i=1;i<=5;i++)
		for (int j=1;j<=i;j++)
		{
			cin>>d1[i][j];
			d2[i][j]=d1[i][j];
			
		}
		//构造数组d2
		int s=1;
		for(int x=5;x>=2;x--)
		{
			for (int y=1;y<=5-s;y++)
			{
				if(d2[x][y]>=d2[x][y+1])
					max=d2[x][y];
				else max=d2[x][y+1];
				
				//cout<<"max="<<max<<endl;
				d2[x-1][y]=max+d2[x-1][y];
			}
			s++;
		}

		//输出b2中的数据
		/*for (int i1=1;i1<=5;i1++)
		{
			for (int j1=1;j1<=i1;j1++)
			{
				cout<<d2[i1][j1]<<" ";	
			}
			cout<<endl;
		}*/
			
		//m横坐标，n纵坐标
		int m=1,n=1;
		
		cout<<"最大值的行走路径为："<<endl;
		//输出第一个路径
		cout<<d1[1][1]<<"  ";

		for(int a=1;a<=5;a++)
		{
			result=d2[m][n]-d1[m][n];
			if (result==d2[m+1][n])
			{
				m=m+1;//m的值每次都要向后移动一位
				cout<<d1[m][n]<<"  ";
			}
			else if(result==d2[m+1][n+1])
			{
				m=m+1;//m的值每次都要向后移动一位
				n=n+1;//n的值向后移动一位
				cout<<d1[m][n]<<"  ";
				
			}
		}
		cout<<endl;
        return 0;
}

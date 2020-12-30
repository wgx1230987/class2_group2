#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void main()
{
	int x,y,t;//x,y,t分别表示行列数和周期
	cout<<"请输入矩阵维度及周期："<<endl;
	cin>>x>>y>>t;
    char m[50][50];
    cout<<"请输入矩阵地图"<<endl;
    for(int i=0;i<y;i++)//循环输入
	{
		for(int j=0;j<x;j++)
		{
			cin>>m[i][j];
		}
	}
    for(int f=0;f<t;f++)//检测周期不为零进入感染循环
{
	for(int k=0;k<y;k++)
	{
		for(int l=0;l<x;l++)
		{
			if(m[k][l]=='X')m[k][l]='B';//先将检测到的感染者替换为B，以免后续检测误判
		}
	}
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(m[i][j]=='B')//感染部分
			{
				m[i][j]='X';
			  if(m[i][j-1]=='O')m[i][j-1]='X';
			  if(m[i][j+1]=='O')m[i][j+1]='X';
			  if(m[i+1][j]=='O')m[i+1][j]='X';
			  if(m[i-1][j]=='O')m[i-1][j]='X';
			}

		}
	}
	}
	cout<<"感染后的矩阵地图:"<<endl;
 for(int p=0;p<x;p++)
	{
		for(int q=0;q<y;q++)
		{
			cout<<m[p][q];
		}
		cout<<endl;
	}
}
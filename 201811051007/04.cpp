#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void main()
{
	int x,y,t;//x,y,t�ֱ��ʾ������������
	cout<<"���������ά�ȼ����ڣ�"<<endl;
	cin>>x>>y>>t;
    char m[50][50];
    cout<<"����������ͼ"<<endl;
    for(int i=0;i<y;i++)//ѭ������
	{
		for(int j=0;j<x;j++)
		{
			cin>>m[i][j];
		}
	}
    for(int f=0;f<t;f++)//������ڲ�Ϊ������Ⱦѭ��
{
	for(int k=0;k<y;k++)
	{
		for(int l=0;l<x;l++)
		{
			if(m[k][l]=='X')m[k][l]='B';//�Ƚ���⵽�ĸ�Ⱦ���滻ΪB����������������
		}
	}
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(m[i][j]=='B')//��Ⱦ����
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
	cout<<"��Ⱦ��ľ����ͼ:"<<endl;
 for(int p=0;p<x;p++)
	{
		for(int q=0;q<y;q++)
		{
			cout<<m[p][q];
		}
		cout<<endl;
	}
}
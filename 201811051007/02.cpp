//2.1����
#include <stdio.h>
#include <stdlib.h>
int getcount(int *p,int m,int n);
int main()
{
    int *p;
    int m,n,i,j,flag,temp;
    while(1){
    scanf("%d%d",&m,&n);
    p=(int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
        p[i]=i+1;
    printf("�����ı��%d\n",getcount(p,m,n));
    }
    free(p);
    return 0;
}
int getcount(int *p,int m,int n)
{
    int i,temp,flag,count;
    temp=0;
    count=m;
     while(count!=1)
    {
        flag=1;             //������
        while(flag<n)   //����Ҫɾ���ĺ��ӵı��
        {
            if(temp>=m)
                temp=0;
            if(p[temp]!=0)
            {
                flag++;
            }
            temp++;
        }
        if(temp>=m)
            temp=0;
        while(temp<m&&p[temp]==0)
            {
                   temp++;
                   if(temp>=m)
                       temp=0;
            }      //������ɾ�����ӵı��
        p[temp]=0;
        count-=1;    //ʣ�º��ӵĸ���-1
    }
    for(i=0;i<m;i++)
    {
        if(p[i]!=0)
        {
            return p[i];
        }
    }
}


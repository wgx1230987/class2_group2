#include<stdio.h>
int main()
{
    int fun(int l,int m);
    int l,m,n;
    printf("Please enter l:\n");
    scanf("%d",&l);  //����������l
    printf("Please enter m:\n");
    scanf("%d",&m);  //����������m
    n=fun(l,m);
    printf("The number n is %d",n);  //���������n
    return 0;
}

int fun(int l,int m)
{
    int n1,n2,n3,n4;  //n1��n2��n3��n4�ֱ��Ӧn��ǧλ����λ��ʮλ����λ
    n1=l%10;
    n2=m/10;
    n3=l/10;
    n4=m%10;
    return (n1*1000+n2*100+n3*10+n4);
}
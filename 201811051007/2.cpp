//2.2������
#include <stdio.h>
#include <stdlib.h>
struct num
{
    int number;
    struct num *next;
};
int getnumber(int m,int n);
int getnumber1(int m,int n);
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("ѭ�������������Ϊ:%d\n\n\n",getnumber(m,n));
    printf("���������������Ϊ:%d\n",getnumber1(m,n));
    return 0;
}
int getnumber(int m,int n)
{
    struct num *p,*p1,*head,*temp;
    int i=0,flag;
    p=(struct num*)malloc(sizeof(struct num));
    head=p;
    while(i<m)
    {
        p1=p;
        p->number=i+1;
        p=(struct num*)malloc(sizeof(struct num));
        p1->next=p;
        i++;
    }
    p1->next=head;     //�γɻ�״�б�
    free(p);
    temp=p1; //temp��ǰָ���ǰ��
    i=1;
    while(i<m)
    {
        flag=1;     //������
        //����Ҫɾ���ı�ŵ�ָ��
        while(flag<n)
        {
            temp=head;
            head=head->next;
            flag++;
        }
        temp->next=head->next;
        printf("ɾ�����ӵı��:%d\n",head->number);
        free(head);
        head=temp->next;
        i++;
    }
    return head->number;
}


int getnumber1(int m,int n)
{
    struct num *p,*p1,*head,*temp;
    int i=0,flag;
    p=(struct num*)malloc(sizeof(struct num));
    head=p;
    if(n==1)
        return m;
    while(i<m)
    {
        p1=p;
        p->number=i+1;
        p=(struct num*)malloc(sizeof(struct num));
        p1->next=p;
        i++;
    }
    p1->next=NULL;   //�γɵ�������
    p=head;
    i=0;
    flag=0;
    while(i!=m-1)
    {
        if(flag==n-1)
        {
            printf("ɾ�����ӵı��:%d\n",p->number);
            if(p==head)   //��ɾ���Ľڵ�λ�ڽڵ�ͷʱ
            {
                head=head->next;
                p=head;
            }
            else if(p->next==NULL) //�����ڵ�λ�ڽڵ�βʱ
            {
                temp->next=NULL;
                p=head;
            }
            else                   //λ���м�
            {
                temp->next=p->next;
                p=p->next;
            }
            i++;
            flag=0;
        }

      //��ָ�뵽������β���ǣ�ʹ��ָ��ͷָ�롣

        if(p->next==NULL)
        {
            p=head;
        }
        else
        {
            temp=p;
            p=p->next;
        }
        flag++;
    }
    return head->number;
}
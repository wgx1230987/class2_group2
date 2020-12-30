//5.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXSIZE 100
//doubleջ�����ڴ�������� 
typedef struct {
	double data[MAXSIZE];
	int top;
}Stack_n;
//charջ�����ڴ�������
typedef struct {
	char data[MAXSIZE];
	int top;
}Stack_c;
//ջ�ĳ�ʼ��
void Init_n(Stack_n s);
void Init_c(Stack_c s);
//ջ���пպ���
int IsEmpty_n(Stack_n s);
int IsEmpty_c(Stack_c s);
//��ջ���� 
void Push_n(Stack_n *s,double e);
void Push_c(Stack_c *s,char e);
//��ջ����
void Pop_n(Stack_n *s,double *e);
void Pop_c(Stack_c *s,char *e);
//ȡջ������
double GetTop_n(Stack_n s);
char GetTop_c(Stack_c s);
 
char Precede(char c1,char c2);//�ж����ȼ� 
double Operate(double a,char theta,double b);//��Ԫ���� 
int In(char c,char *OP);//�Ƿ�Ϊ + - * / ( ) 
void check(char *s);//���ڼ������Ķ���ʽ��ʽ�Ƿ���ȷ
double Poland(char * s);//��Ҫ����ʵ�ֺ���
 
char OP[7]={'+','-','*','/','(',')','#'}; //���������(��������ʹ�ù�����Ϊ���е�)
 
int main(){
	char s[100];
	printf("��������ʽ��\n");
	gets(s);
	double r = Poland(s);
	printf("%1.2lf\n",r);
	return 0;	
}
 
void Init_n(Stack_n *s){
	s->top = 0;
}
 
void Init_c(Stack_c *s){
	s->top = 0;
}
//ջ���пպ���
int IsEmpty_n(Stack_n s){
	if(s.top == 0){
		return 1;
	}
	else{
		return 0;
	}
}
int IsEmpty_c(Stack_c s){
	if(s.top == 0){
		return 1;
	}
	else{
		return 0;
	}	
}
//��ջ���� 
void Push_n(Stack_n *s,double e){
	s->top++;
	s->data[s->top] = e;
}
void Push_c(Stack_c *s,char e){
	s->top++;
	s->data[s->top] = e;
}
//��ջ����
void Pop_n(Stack_n *s,double *e){
	*e = s->data[s->top];
	s->top--;
}
void Pop_c(Stack_c *s,char *e){
	*e = s->data[s->top];
	s->top--;
}
//ȡջ������
double GetTop_n(Stack_n s){
	return s.data[s.top];
}
char GetTop_c(Stack_c s){
	return s.data[s.top];
}
 
char Precede(char c1,char c2){
	//�ж��������ջ������������������֮�����ȹ�ϵ
    char c;
    switch(c1){
        case '+':
        case '-':
	    	switch(c2){
		        case '+':
	            case '-':
		        case ')':
	            case '#':
			    	c='>';
	               	break;
		        default:
			    	c='<';
	    	}
        	break;
        case '*':
        case '/':
            if(c2=='('){
				c='<';
			}
			else{
				c='>';
			}
            break;
        case '(':
		    if(c2==')'){
				c='=';
			}
		    else{
				c='<';
			}
            break;
        case ')':
	    	c='>';
            break;
        case '#':
		    if(c2=='#'){
				c='=';
			}
		    else{
				c='<';
			}
    }
    return c;
}
 
double Operate(double a,char theta,double b){
	//���ж�Ԫ���� a theta b
	double sum;
    switch(theta)
    {
       case '+':
	   sum=a+b;
	   break;
       case '-':
	   sum=a-b;
	   break;
       case '*':
           sum=a*b;
           break;
       case '/':
           sum=a/b;
	   break;
    }
    return sum;
}
 
int In(char c,char *OP){
    //�ж��ǲ��������
    for(int i=0;i<7;i++)
       if(c==OP[i])   //�������
          return 1;
    return 0;
}
//�ж�˼·����ǰ�ַ����������ǰһλ���һλҲ�����������3λ����Ϊ�������͡�����ʱ˵���������������������
void check(char *s){
	char *t = s;
	for(int i = 0;i < strlen(s);i++){
		if(i > 0 && i < strlen(s) - 1 && In(s[i],OP) && (In(s[i - 1],OP) || In(s[i + 1],OP))
			&&(s[i] != '(' && s[i] != ')') && (s[i - 1] != '(' && s[i - 1] != ')')
			&&(s[i + 1] != '(' && s[i + 1] != ')')){
			printf("�����ʽ���󣡣������Ƿ��������������������ȴ��󣡣�\n");
			getchar();
			exit(0);
		}
	}
}
 
double Poland(char * s){
	//�Զ���ʽ��ʽ���м��
	check(s);
    //���ж���ʽ����ֵ�Լ���׺���ʽ�����
    int i=0,len,flag=0;
    double a,b,sum;
    char c1=s[0],e;
    
    Stack_c OPTR; 	//�����ջ
    Stack_n OPND; 	//������ջ
    Init_c(&OPTR);  //��ʼ��ջ
    Init_n(&OPND);
    
    len=strlen(s);
    s[len]='#';
    s[len+1]='\0';
    Push_c(&OPTR,'#');//����#����Ϊ������־
    while(s[i]!='#'||GetTop_c(OPTR)!='#'){ //����ÿһ���ַ� Ϊ��#������ѭ��
		if(s[i] == ' '){
			i++;
			continue;
		}
        if(!In(s[i],OP)){ //������������
	        if(c1=='.'){//�����һ���ַ���С����
		        flag++;
		    }
		    if(flag){
		    	double t;
		    	Pop_n(&OPND,&t);
				Push_n(&OPND,t + (double)(s[i] - '0') / pow(10,flag));//��С�����Ĳ��� ��λ�����㲢��ջ 
				flag++;
			}
	        if(s[i]!='.'&&!flag){
	            if(!In(c1,OP)&&!IsEmpty_n(OPND)){//�����һ���ַ������֣�˵���Ƕ�λ���� ����λ���������ջ
	            	double t;
	            	Pop_n(&OPND,&t);
	                Push_n(&OPND,t * 10 + s[i] - '0');
	            }
	            else//����ѹ��������ջ
	            	Push_n(&OPND,(double)(s[i]-'0'));
		    }
	    	c1=s[i++]; //��ȡ��һ���ַ�
	    }
        else{//����������
            flag=0;
            switch(Precede(GetTop_c(OPTR),s[i])){
                 case '>':  //��ǰ��������ȼ���
		             Pop_c(&OPTR,&e); //�������ջ,�Ͳ�������ͷ���������� 
		             Pop_n(&OPND,&b);
                     Pop_n(&OPND,&a);
		             Push_n(&OPND,Operate(a,e,b)); //��������ջ
                     break;
                 case '=': //���ȼ����
		             Pop_c(&OPTR,&e); //���������ջ��Ԫ��
		             c1 = s[i++];
                     break;
                 case '<':
		          	Push_c(&OPTR,s[i]); //��ǰ��������ȼ��� ��ջ
		            c1 = s[i++];
                    break;
	    	}
        }
    }
    sum=GetTop_n(OPND);
    return sum; //����������ջ��Ԫ�أ��������� 
}
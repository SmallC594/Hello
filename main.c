#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
 int key;//ÿ���˳��е�����
 int num;//����˵ı��
 struct Node *next;//ָ����һ���ڵ�
}Node,Link;
//=================================
Node* InitList();
void Creater(int n,Link* L) ;
int main()
{
 Link *p,*q;
 Node * HEAD;
 int n,x;
 HEAD=InitList();//�����һ��ֻ��ͷ���Ŀ�����
 printf("please input the totle number of people:");
 scanf("%d",&n);//�ܹ�������n
 printf("the first key is:");
 scanf("%d",&x);//��ʼ����Ϊx
 Creater(n,HEAD);//������һ��Լɪ��
 p=HEAD;
 int i;
 int j;
 int Temp;

 for(i=1;i<=n;i++)
 {
  for(j=1;j<x;j++)
  p=p->next;
  q=p->next;
  x=q->key;
  Temp=q->num;
 // printf("%d  ",x);
  printf("%d  ",Temp);
  p->next=q->next;
 // free(q);
 }
 return 0;
}
Node* InitList()           //����һ���յ�����
{
 Node * L;
 L=(Node *)malloc(sizeof(Node));
 if(!L) exit(1);
 L->key=0;
 L->num=0;
 L->next=NULL;
 return L;
}
void Creater(int n,Link *L)     //��ʼ������  Ԫ����ĿΪn
{
 Link *p,*q;
 q=L;
 int i;
 int Tempdata;
 for( i=1;i<=n;i++)
 {
  p=(Node *)malloc(sizeof(Node));
  if(!p) exit(1);
  printf("Please enter the key:");
  scanf("%d",&Tempdata);
  p->key=Tempdata;
  p->num=i;
  L->next=p;
  L=p;
 }
 L->next=q->next;           //�γ�ѭ������  ����βԪ�غ��ָ������ͷԪ��

 printf("%d\n",q->next->num);   //ͷ�����ָ��ͷԪ��
 printf("%d\n",L->next->num);    //βԪ�غ��ָ��ͷԪ��
 printf("%d\n",L->next->next->num);  //�ڶ�Ԫ��numֵ   ��֤ѭ�����������
 free(q);
}

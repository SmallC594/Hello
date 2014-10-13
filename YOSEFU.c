#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
 int key;//每个人持有的密码
 int num;//这个人的编号
 struct Node *next;//指向下一个节点
}Node,Link;
//=================================
Node* InitList();
void Creater(int n,Link* L) ;
int main()
{
 Link *p,*q;
 Node * HEAD;
 int n,x;
 HEAD=InitList();//构造出一个只有头结点的空链表
 printf("please input the totle number of people:");
 scanf("%d",&n);//总共的人数n
 printf("the first key is:");
 scanf("%d",&x);//初始密码为x
 Creater(n,HEAD);//建立好一个约瑟夫环
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
Node* InitList()           //创建一个空的链表
{
 Node * L;
 L=(Node *)malloc(sizeof(Node));
 if(!L) exit(1);
 L->key=0;
 L->num=0;
 L->next=NULL;
 return L;
}
void Creater(int n,Link *L)     //初始化链表  元素数目为n
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
 L->next=q->next;           //形成循环链表  链表尾元素后继指向链表头元素

 printf("%d\n",q->next->num);   //头结点后继指向头元素
 printf("%d\n",L->next->num);    //尾元素后继指向头元素
 printf("%d\n",L->next->next->num);  //第二元素num值   验证循环链表创建完成
 free(q);
}

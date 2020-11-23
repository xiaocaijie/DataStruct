#include<stdio.h>
#include<stdlib.h>


#define NULL 0

typedef struct Node {

	int data;
	struct Node * next;

}Node,*LinkList;
//全局变量
LinkList h;
LinkList *p = &h;


void main () {
	//函数声明
void InitList (LinkList *L);//建立头节点
void CreateFromHead (LinkList L);//初始化链表---头插入法
void VreateFromTail(LinkList L);//初始化链表---尾部插入法
void Show(LinkList h); //打印链表
int ListLength (LinkList L); // 获取链表长度

LinkList Get (LinkList L , int i); //按位查找
LinkList Locate(LinkList L, int e);//按值查找
int  InsList (LinkList L,int i, int e); //插入元素
int DelList (LinkList L ,int i,int *e );//删除元素
void RemoveDuplicates(LinkList L); //删除有序链表的重复元素

	/* 
	菜单  
	 */
 
void Search(); //查询
void Delect (); //删除
void Insert(); //插入
void innit (LinkList *L ) ;// 初始化
int flag = 1,select;

while (flag !=0) {
printf ("输入 0退出 1初始化  2插入 3删除 4查询 5打印链表 6获取链表长度 7删除有序链表的重复元素\n:");
scanf("%d",&select);
switch (select) {
case 0 : flag = 0; break;
case 1 : innit (p);break;
case 2 : Insert(); break;
case 3 : Delect(); break;
case 4 : Search(); break;
case 5 : Show(h);break;
case 6 :printf("链表当前长度为:%d \n", ListLength(h));break;
case 7 :RemoveDuplicates(h); break;
default : printf("输入有误 请重新输入"); 
}
}
}

//菜单--查寻

void Search() {
LinkList result;
int flag,e,select; 
flag =1;
while (flag) {
//查询
printf("输入 1按位查找， 2 按值查找:");
scanf("%d",&select);


if (select == 1){
printf("请输入要查询的位置：");
scanf("%d",&e);
result = Get (h,e);
}else {
printf("请输入要查询的数据：");
scanf("%d",&e);
result = Locate(h,e);
}



if(result != NULL) {
	printf("查询成功: %d\n",result->data);

}else {
	printf("没有找到");
}

printf("继续查询请输入 1  退出输入0:");
scanf("%d",&flag);

}
}

//菜单---删除
void Delect () {
int flag = 1,i,e; 
while (flag) {

printf("请输入要删除的位置：");
scanf("%d",&i);
if (DelList (h,i,&e)){
	printf("删除成功 ");
	printf("删除的元素的值为%d\n",e);
	Show(h);
}else {
	printf("删除失败");

}
printf("继续删除请输入 1  退出输入0:");
scanf("%d",&flag);


}
}



//菜单---插入
void Insert() {
int flag=1,e,i;
while (flag) {
printf("请输入要插入的数据:");
scanf("%d",&e);
printf("请输入要插入的位置:");
scanf("%d",&i);

if(InsList( h,i,e )) {
	printf("插入成功");
	Show(h);
}else {

	printf("插入失败");
}

printf("继续插入请输入 1  退出输入0:");
scanf("%d",&flag);


} 

}




//菜单 -- 初始化链表
void innit (LinkList *L )  {
int select;
InitList(L) ; //初始化头结点
printf("请输入0退出 1头插法 2尾插法:");
scanf("%d",&select);
switch (select) {
	case 1: CreateFromHead (h); break;
	case 2: VreateFromTail(h); break;
	default : printf("输入不合法 退出初始化");break;

}
Show(h);
}





//删除
int DelList (LinkList L ,int i,int *e ) {
LinkList pre,r;
int k = 0;
pre = L;

while ((pre->next !=NULL) && (k < i-1)) {
	pre = pre->next;
	k++;
}
if(pre->next == NULL) {
	printf("删除的位置不合理");
	return 0;
}

r = pre->next;
*e = r->data;//记录删除的值
pre->next = r->next;
free(r);
return 1;

}

//插入
int  InsList (LinkList L,int i, int e) {
 LinkList pre ,s ;
 int k = 0 ;
 if(i <= 0) return 0;
 pre = L ;
 while ((pre!=NULL) && (k < i-1)) {
	pre = pre->next;
	k++;
 }
 if(pre == NULL) {
	printf("插入位置不合法");
	return 0;
 }
 s = (LinkList) malloc(sizeof(Node));
 s->data = e ;
 s->next = pre->next;
 pre->next = s;
 return 1 ;
}

//获取链表长度 
int ListLength (LinkList L) {
	LinkList p;
	int i=0;
	p = L->next;
	
	while (p != NULL){
		p = p->next;
		i++;
	}
return i;

}

/*  
	查询

*/
//按值查找
LinkList Locate(LinkList L, int e) {
LinkList p;
int i = 1;
p = L->next;

while (p != NULL && (p->data != e)) {
	p = p->next;
	i++;
} 
if(p != NULL){
	printf("寻找到%d在位置%d",e,i);
	return p;
}else{
	printf("未找到");
	return NULL;
}
}

//按位查找
LinkList Get (LinkList L , int i) {
int j; 
LinkList p;
if(i <= 0 ){return NULL;}
p=L;
j=0;
while ((p->next!=NULL) && (j<i)) {
	p = p->next;
	j++;

}
if( i == j) {
	return p;
}else return NULL;

}

/*
	初始化
*/
	//头插法

void CreateFromHead (LinkList L) {
Node *s;
int data;
int n,i=0;
printf("请输入要插入数据的个数");
scanf("%d",&n);
while (i<n) {
printf("请输入第%d个数据:",i+1);
scanf("%d",&data);
s = (Node *) malloc(sizeof(Node));//建立新节点
s->data = data;
s->next = L->next;
L->next = s;
i++;
}
}
	//尾插法
void VreateFromTail(LinkList L) {
LinkList r,s;
int d;
int n,i=1;
printf("请输入要插入数据的个数");
scanf("%d",&n);
r = L;
while (i <= n) {
printf("请输入第%d个数据:",i);
scanf("%d",&d);
s = (LinkList) malloc(sizeof(Node));//建立新节点
s->data = d;
r->next = s;
r = s ;
if(n == i) {
//最后的next域为NULL
	r->next = NULL;	
} 
i++;
}

}

//初始化头节点
void InitList (LinkList *L) {

	*L = (LinkList) malloc(sizeof(Node));//建立头节点
	(*L)->next = NULL;
	printf("头节点建立成功\n");

}


//打印链表
void Show(LinkList h) {
	printf("\n");
	printf("链表元素为:");
	while (h->next != NULL) {
		printf("%d ",h->next->data);
		h = h->next;
	}
	printf("\n");	

}

//去重
void RemoveDuplicates(LinkList L) {
LinkList pre,p,temp;
pre = L->next;
p = pre->next;

while(p != NULL) {
	if(pre->data == p->data){
		temp = p;
		p = p->next;
		free(temp);
	}else{
		pre->next = p;
		pre = p;
		p = p->next;

	}
}

pre->next = NULL;//最后元素next值为NULL
}

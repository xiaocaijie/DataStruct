#include <stdio.h>
#define MAXSIZE 100
//定义
typedef struct {
int elem[MAXSIZE];
int last;
}SeqList, *LinkList;

SeqList seqList;
LinkList p = &seqList;
void main() {
void dispalyList(SeqList List); //打印elem[]
void innit (LinkList p ); //初始化elem[]
int InsList(LinkList p, int i , int e );//插入
int DelList (LinkList p,int i,int *e);//删除
int Locate (SeqList L, int e);//查询
//菜单
void Search(); 
void Delect ();
void Insert();
int flag = 1,select;

while (flag !=0) {
printf ("输入 0退出 1初始化  2插入 3删除 4查询 5输出线性表 :");
scanf("%d",&select);
switch (select) {
case 0 : flag = 0; break;
case 1 : innit(p); break;
case 2 : Insert(); break;
case 3 : Delect (); break;
case 4 : Search(); break;
case 5 : dispalyList(seqList);break;
}

} 

}


void Search() {
int flag= 1,e,i; 
while (flag) {
//查询
printf("请输入要查询的数据：");
scanf("%d",&e);
i = Locate ( seqList,e);
if(i!= -1) {
	printf("查询成功 %d位置为%d\n",e,i);

}else {
	printf("没有找到");
}

printf("继续查询请输入 1  退出输入0:");
scanf("%d",&flag);

}
}

//删除
void Delect () {
int flag = 1,i,e; 
while (flag) {
//删除
printf("请输入要删除的位置：");
scanf("%d",&i);
if (DelList ( p,i,&e)){
	printf("删除成功 删除元素为:%d\n",e);
	dispalyList(seqList);
}else {
	printf("删除失败");

}
printf("继续删除请输入 1  退出输入0:");
scanf("%d",&flag);


}
}



//插入
void Insert() {
int flag=1,e,i;
while (flag) {

//插入
printf("请输入要插入的数据:");
scanf("%d",&e);
printf("请输入要插入的位置:");
scanf("%d",&i);

if(InsList( p,i,e )) {
	printf("插入成功");
	dispalyList(seqList);
}else {

	printf("插入失败");
}

printf("继续插入请输入 1  退出输入0:");
scanf("%d",&flag);


} 

}



void innit (LinkList p )  {
int i,n;
printf("请输入数据的总数:");
scanf("%d",&n);
p->last = n-1;
printf("初始化数据\n");
for (i = 0; i <= p->last ; i++) {
printf("请输入第%d个元素:",i+1);
scanf("%d",&p->elem[i]);
}

}


//输出elem[]
void dispalyList(SeqList List){
int i ;
printf("元素为：\n");

for (i = 0; i <= List.last; i++) {
	//输出elem[]
	printf("%d ",List.elem[i]);

}
printf("\n");
}

//插入
int InsList(LinkList p, int i , int e ) {
	int k;
	if(i < 1 || i > p->last + 2) {
	 printf("插入位置不合法");
		return 0;
	}
	if (p->last >= MAXSIZE - 1) {
	 printf("表满了，无法插入");
	 return 0;
	}
	for (k = p->last; k >= i-1 ; k--) {
		p->elem[k+1] = p->elem[k];
	}
	p->elem[i-1] = e;
	p->last++;
	return 1;

}

//删除
int DelList (LinkList p,int i,int *e) {
int k; 
if(i<1 || (i > p->last)) {
	printf("删除位置不合法");
	return 0;
}
*e = p->elem[i -1];
for (k = i; k<= p->last ; k++) {
	p->elem[k-1] = p->elem[k];
	
} 
p->last--;
return 1;


}

int Locate (SeqList L, int e) {
int i=0 ;
while ((i<=L.last) && (L.elem[i]!=e)) 
i++;
if(i <= L.last){
	return (i+1);
}else {
	return (-1);

}

}
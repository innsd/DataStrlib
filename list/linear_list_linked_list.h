#ifndef _LINEAR_LIST_LINKED_LIST_
#define _LINEAR_LIST_LINKED_LIST_
#include <malloc.h>
#define ERROR -1
#define SUCCESS 0
typedef int ElementType;
typedef struct LNode * List;
struct LNode{
	ElementType Data;
	List Next;
};
List MakeEmpty();//Initialize the List and return it
List FindKth(int K,List L);//Find the Kth Element and return it's point
List Find(ElementType X,List L);//Find the X int List L and return the point
List Insert(ElementType X,int i,List L);//Insert Element X in list L,i is the index
List Delete(int i,List L);//Delete the i-th Element int list L
int Length(List L);//return the Length of list L
int IsEmpty(List L);//return 1 is Empty
List MakeEmpty(){
	List Header=(List)malloc(sizeof(struct LNode));
	Header->Data=NULL;
	Header->Next=NULL;
	return Header;
}
List FindKth(int k,List L){
	if(k<0||k>Length(L)) return NULL;
	List p=L;
	int i=0;
	for(;i<k;i++){
		p=p->Next;
	}
	return p;
}
List Find(ElementType X,List L){
	List p=L;
	while(p!=NULL&&p->Data!=X) p=p->Next;
	return p;
}
List Insert(ElementType x,int i,List L){
	if(L==NULL) return NULL;//如果L不存在返回NULL
	List p=NULL;//p用于申请新节点
	List s=NULL;
	if(i==0){//处理在头部插入的情况
		p=(List)malloc(sizeof(struct LNode));
		if(p==NULL) return NULL;
		p->Next=L;
		p->Data=x;
		return p;
	}
	s=FindKth(i-1,L);
	if(s==NULL) return NULL;
	else if(p=(List)malloc(sizeof(struct LNode))){
			p->Data=x;
			p->Next=s->Next;
			s->Next=p;//s是i-1节点的指针，第i-1节点指向p，即p在i的位置上
			return L;
	}else return NULL;
}
List Delete(int i,List L){
	if(L==NULL) return NULL;
	List p=NULL,s=NULL;
	if(i==0){
		s=L;
		L=L->Next;
		free(s);
		return L;
	}
	if(p=FindKth(i-1,L)) return NULL;
	s=p->Next;
	p->Next=p->Next->Next;
	free(s);
	return L;
}
int Length(List L){
	int i=0;
	while(1){
		L=L->Next;
		if(L=NULL) break;
		else i++;
	}
	return i;
}
#endif

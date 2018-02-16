/*linear list in array
 * code:chengxiangrui
 * v:1.0
 *
*/
#ifndef LINEAR_LIST_ARRAY_H
#define LINEAR_LIST_ARRYA_H
#define MAXSIZE 100
#include <malloc.h>
#define ERROR -1
#define SUCCESS 0
typedef int ElementType;
typedef struct LNode * List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};
List MakeEmpty();//Initialize the List and return it
ElementType FindKth(int K,List L);//Find the Kth Element and return it
int Find(ElementType X,List L);//Find the X int List L 
int Insert(ElementType X,int i,List L);//Insert Element X in list L,i is the index
int Delete(int i,List L);//Delete the i-th Element int list L
int Length(List L);//return the Length of list L
int IsEmpty(List L);//return 1 is Empty
int IsFull(List L);//return 1 is Full
List MakeEmpty(){
	List Ptrl;
	Ptrl=(List)malloc(sizeof(struct LNode));
	Ptrl->Last=-1;
	return Ptrl;
}
int Find(ElementType X,List L){
	int i=0;
	while(i<=L->Last && L->Data[i]!=X) i++;
	if(i>L->Last) return ERROR;
	else return i;
}
int Insert(ElementType X,int i,List L){
	int j=0;
	if(L->Last==MAXSIZE-1) return ERROR;//判断表慢
	if(i<0||i>L->Last) return ERROR;//判对位置错误
	for(j=L->Last;j>=i;j--)
		L->Data[j+1]=L->Data[j];
	L->Data[i]=X;
	L->Last++;
	return SUCCESS;
}
int Delete(int i,List L){
	int j=i;
	if(i<0||i>L->Last) return ERROR;
	while(j<L->Last) L->Data[j]=L->Data[++j];
	L->Last--;
	return SUCCESS;
}
int Length(List L){
	return L->Last;
}
int IsEmpty(List L){
	if(L->Last<0) return 1;//return 1 is Empty
	else return 0;
}
int IsFull(List L){
	if(L->Last==MAXSIZE-1) return 1;//return 1 is Full
	else return 0;
}
#endif

/*
 *堆栈的链表方式实现
 ×
*/
#ifndef _STACK_LINKED_LIST_H_
#define _STACK_LINKED_LIST_H_
#define ERROR -1
#define SUCCESS 0
#include <malloc.h>
typedef int ElementType;
typedef struct SNode * Stack;
struct SNode{
    ElementType Data;
    Stack Next;
};

Stack CreateStack();
int Push(Stack S,ElementType x);
ElementType Pop(Stack S);
int IsEmpty(Stack S);//return 1 is empty
Stack CreateStack(){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}
int Push(Stack S,ElementType x){
    Stack p=(Stack)malloc(sizeof(struct SNode));
    if(p==NULL) return ERROR;
    else{
        p->Data=x;
        p->Next=S;
        S=p;
        return SUCCESS;
    }
}
ElementType Pop(Stack S){
    if(IsEmpty(S)) return NULL;//如果堆栈S空 返回NULL
    Stack p=S;
    ElementType Temp=p->Data;
    S=S->Next;
    free(p);
    return Temp;
}
int IsEmpty(Stack S){
    return S->Next==NULL;
}
#endif
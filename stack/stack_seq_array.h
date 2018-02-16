/*使用顺序数组构造堆栈
 *_STACK_SEQ_ARRAY_H_
*/
#ifndef _STACK_SEQ_ARRAY_H_
#define _STACK_SEQ_ARRAY_H_
#include <malloc.h>
#define ERROR -1
#define SUCCESS 0
typedef int ElementType;//可以修改int 为其他<类型/结构体>
typedef struct SNode * Stack;
struct SNode{
    ElementType *Data;
    int top;//top是指针指向栈顶
    int MAXSIZE;//此变量保存了栈的最大长度
};
Stack CreateStack(int maxsize);
int Push(Stack S,ElementType x);
ElementType Pop(Stack S);
int IsFull(Stack S);//return 1 is full
int IsEmpty(Stack S);//return 1 is empty
//********************************
Stack CreateStack(int maxsize){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    if(S==NULL) return NULL;
    S->Data=(ElementType*)malloc(sizeof(ElementType)*maxsize);
    S->MAXSIZE=maxsize;
    S->top==-1;
    return S;
}
int Push(Stack S,ElementType x){
    if(S->top==S->MAXSIZE-1) return ERROR;
    else{
        S->Data[++(S->top)]=x;
        return SUCCESS;
    }
}
ElementType Pop(Stack S){
    if(S->top==-1) return ERROR;
    else{
        return S->Data[(S->top)--];
    }
}
int IsEmpty(Stack S){
    if(S->top==-1) return 1;
    else return 0;
}
int IsFull(Stack S){
    if(S->top==S->MAXSIZE-1) return 1;
    else return 0;
}

#endif
#ifndef _QUEUE_LINKED_LIST_
#define _QUEUE_LINKED_LIST_
#include <malloc.h>
#define ERROR -1
#define SUCCESS 0
typedef int ElementType;
struct Node{
    ElementType Data;
    struct Node * Next;
};
struct QNode{
    struct Node * front;
    struct Node * rear;
};
typedef struct QNode * Queue;
Queue CreateQueue();
int AddQ(Queue Q,ElementType x);
ElementType DelQ(Queue Q);
int IsEmpty(Queue Q);
Queue CreateQueue(){
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    if(Q==NULL) return NULL;
    Q->front=NULL;
    Q->rear=NULL;
    return Q;
}
int IsEmpty(Queue Q){
    if(Q->front==NULL||Q->rear==NULL) return 1;
    else return 0;
}
int AddQ(Queue Q,ElementType x){
    struct Node * temp=(struct Node *)malloc(sizeof(struct Node));
    if(temp==NULL) return ERROR;
    temp->Data=x;
    temp->Next=NULL;
    if(IsEmpty(Q)){
        Q->front=temp;
        Q->rear=temp;
        return SUCCESS;
    }else{
        Q->rear->Next=temp;
        Q->rear=temp;
        return SUCCESS;
    }
}
ElementType DelQ(Queue Q){
    ElementType TempElement=NULL;
    struct Node * TempPtrQ=NULL;
    if(IsEmpty(Q)) return ERROR;
    if(Q->front==Q->rear){
        TempElement=Q->front->Data;
        free(Q->front);
        Q->front=NULL;
        Q->rear=NULL;
        return TempElement;
    }else{
        TempElement=Q->front->Data;
        TempPtrQ=Q->front;
        Q->front=Q->front->Next;
        free(TempPtrQ);
        return TempElement;
    }
}

#endif
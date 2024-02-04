#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;//int 재정의

typedef struct tagNode //태그노드
{
    ElementType Data;
} Node;

typedef struct tagCircularQueue
{
    int   Capacity; //용량
    int   Front; //전단 rotation
    int   Rear; //후단  rotation

    Node* Nodes; //배열의 첫번째 요소 저장 
} CircularQueue;

void        CQ_CreateQueue( CircularQueue** Queue, int Capacity); //
void        CQ_DestroyQueue( CircularQueue* Queue ); //
void        CQ_Enqueue( CircularQueue* Queue, ElementType Data); //
ElementType CQ_Dequeue( CircularQueue* Queue ); //
int         CQ_GetSize( CircularQueue* Queue ); //
int         CQ_IsEmpty( CircularQueue* Queue ); //
int         CQ_IsFull( CircularQueue* Queue ); //

#endif

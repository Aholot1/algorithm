#ifndef LINKED_QUEUE_H// 복수선언 해결
#define LINKED_QUEUE_H

#include <stdio.h>
#include <string.h>//문자열 컨트롤을 위한 라이브러리
#include <stdlib.h>

typedef struct tagNode //링크드 리스트(Basic)
{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
    Node* Front; //전단 포인터
    Node* Rear; //후단 포인터
    int   Count; //노드갯수 
} LinkedQueue;

void  LQ_CreateQueue( LinkedQueue** Queue ); //큐 생성
void  LQ_DestroyQueue( LinkedQueue* Queue );// 큐 파괴

Node* LQ_CreateNode(char* Data);// 노드 생서
void  LQ_DestroyNode(Node* _Node );// 노드 파괴

void  LQ_Enqueue( LinkedQueue* Queue, Node* NewNode );//노드 대입
Node* LQ_Dequeue( LinkedQueue* Queue );//노드 제외

int   LQ_IsEmpty( LinkedQueue* Queue );// 노드 체크

#endif

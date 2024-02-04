#ifndef LINKEDLIST_H//중복 포함문제 해결
#define LINKEDLIST_H//매크로

#include <stdio.h>// 표준입출력
#include <stdlib.h>//표준 라이브러리

typedef int ElementType;// 타입 재정의

typedef struct tagNode// 구조체 타입 재정의
{
    ElementType Data;// int 타입
    struct tagNode* NextNode;// 자신과 같은 타입을 가리키는 포인터(다음과 이 노드를 연결하는 고리 포인터)
} Node;

// 함수 원형 선언 
Node* SLL_CreateNode(ElementType NewData);//노드 생성
void  SLL_DestroyNode(Node* Node);//노드 헤제
void  SLL_AppendNode(Node** Head, Node* NewNode);// 노드 추가
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void  SLL_InsertAfter(Node* Current, Node* NewNode);
void  SLL_InsertNewHead(Node** Head, Node* NewHead);
void  SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int   SLL_GetNodeCount(Node* Head);

#endif

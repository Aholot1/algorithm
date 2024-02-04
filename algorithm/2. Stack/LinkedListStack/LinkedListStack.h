#ifndef LINKEDLIST_STACK_H // 복수선언 방지 
#define LINKEDLIST_STACK_H

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
// 링크드 리스트 구조체
typedef struct tagNode
{
    char* Data;
    struct tagNode* NextNode;
} Node;
//링크드 리스트로 구현하는 스택 구조체
typedef struct tagLinkedListStack
{
    Node* List;
    Node* Top;
} LinkedListStack;
//스택 생성&파괴
void  LLS_CreateStack( LinkedListStack** Stack ); //스택 생성
void  LLS_DestroyStack( LinkedListStack* Stack ); //스택 파괴
//노드 생성&파괴
Node* LLS_CreateNode( char* Data ); //노드 생성
void  LLS_DestroyNode( Node* _Node ); //노드 파괴
//스택의 노드 함수
void  LLS_Push( LinkedListStack* Stack, Node* NewNode ); //노드 삽입
Node* LLS_Pop( LinkedListStack* Stack ); // 노드 제외
//스택에 대한 함수
Node* LLS_Top( LinkedListStack* Stack ); //스택의 최상위 노드 반환
int   LLS_GetSize( LinkedListStack* Stack ); //스택의 크기 반환
int   LLS_IsEmpty( LinkedListStack* Stack ); // 스택의 공허 유무 판단 

#endif

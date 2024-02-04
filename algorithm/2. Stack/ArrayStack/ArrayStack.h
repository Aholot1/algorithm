#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode // 데이터를 담는 구조체 
{
    ElementType Data; // 데이터
} Node; 

typedef struct tagArrayStack // 스택
{
    int   Capacity; //용량
    int   Top;// 탑 노드 위치 
    Node* Nodes; // 힙영역에 할당한 배열의 첫번째 요소 가리키는 용도 
} ArrayStack;

void        AS_CreateStack(ArrayStack** Stack, int Capacity);// 스택 생성
void        AS_DestroyStack(ArrayStack* Stack);// 스택 파괴
void        AS_Push(ArrayStack* Stack, ElementType Data);// 노드 삽입
ElementType AS_Pop(ArrayStack* Stack); //스택 제거
ElementType AS_Top(ArrayStack* Stack); // 스택 최상위 노드 체크
int         AS_GetSize(ArrayStack* Stack); // 스택 노드 갯수
int         AS_IsEmpty(ArrayStack* Stack); // 스택이 비어있는가? 
int         AS_IsFull(ArrayStack* Stack);
#endif

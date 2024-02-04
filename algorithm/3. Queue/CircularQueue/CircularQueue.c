#include "CircularQueue.h"

void  CQ_CreateQueue( CircularQueue** Queue, int Capacity)
{
    //  큐를 자유 저장소에 생성 
    (*Queue )           = ( CircularQueue*)malloc(sizeof( CircularQueue ));

    //  입력된 Capacity+1 만큼의 노드를 자유 저장소에 생성 
    (*Queue )->Nodes    = (Node*)malloc(sizeof(Node )* ( Capacity+1) );

    (*Queue )->Capacity = Capacity;
    (*Queue )->Front = 0;
    (*Queue )->Rear  = 0;
}

void CQ_DestroyQueue( CircularQueue* Queue )
{
    free(Queue->Nodes); //큐의 노드 파괴
    free(Queue ); //큐 파괴
}

void CQ_Enqueue( CircularQueue* Queue, ElementType Data)
{
    int Position=0;
  
    if(Queue->Rear==Queue->Capacity) //후단이 배열의 끝에 도착
    {
        Position=Queue->Rear; //후단을 포지션에 저장
        Queue->Rear=0; //후단을 0으로 초기화()
    }
    else
        Position=Queue->Rear++;
  
    Queue->Nodes[Position].Data=Data;
}

ElementType CQ_Dequeue( CircularQueue* Queue )//전단 제거 
{
    int Position = Queue->Front;//전단의 위치

    if ( Queue->Front == Queue->Capacity )//만약 전단의 위치가 용량과 같다 -> 배열의 끝이다.
        Queue->Front = 0;//전단을 가장 앞으로
    else
        Queue->Front++;

    return Queue->Nodes[Position].Data;
}

int CQ_GetSize( CircularQueue* Queue )
{
    if ( Queue->Front <= Queue->Rear )
        return Queue->Rear - Queue->Front;
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty( CircularQueue* Queue )
{
    return (Queue->Front == Queue->Rear);
}

int CQ_IsFull( CircularQueue* Queue )
{
    if ( Queue->Front < Queue->Rear )
        return ( Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return ( Queue->Rear + 1 ) == Queue->Front;
}

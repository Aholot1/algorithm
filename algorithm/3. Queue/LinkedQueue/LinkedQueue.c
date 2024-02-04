#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue ) //큐 생성(할당)
{
    //  큐를 자유 저장소에 생성 
    (*Queue )        = ( LinkedQueue*)malloc(sizeof( LinkedQueue ) );
    (*Queue )->Front = NULL;
    (*Queue )->Rear  = NULL;
    (*Queue )->Count = 0;
}

void LQ_DestroyQueue( LinkedQueue* Queue )//큐 파괴
{
    while ( !LQ_IsEmpty( Queue ) )// 큐가 남아있다면
    {
        Node* Popped = LQ_Dequeue( Queue );//남은 노드를 모두파괴
        LQ_DestroyNode(Popped);    
    }

    //  큐를 자유 저장소에서 할당 해제 
    free( Queue );//마지막으로 자폭
}

Node* LQ_CreateNode( char* NewData )// 노드 생성(매개벼수로 문자열까지)
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );// 노드의 크기만큼 할당
    NewNode->Data = (char*)malloc( strlen( NewData) + 1);// 널문자를 포함안 길이만큼 할당

    strcpy(NewNode->Data, NewData);  //  데이터를 저장한다. 대입

    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화한다.// 다른건 대입에서 

    return NewNode;//  노드의 주소를 반환한다. 
}

void  LQ_DestroyNode(Node* _Node )//노드 파괴
{
    free(_Node->Data);//노드 안에도 동적할당이기에 파괴
    free(_Node );// 노드파괴
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )// 노드대입
{
    if ( Queue->Front == NULL ) // 만약 전단이 널, 즉 노드가 단 하나라면
    {        
        Queue->Front = NewNode;// 앞 노드는 대입하는 노드
        Queue->Rear  = NewNode;// 뒤 노드도 대입하는 노드 
        Queue->Count++;
    } 
    else //노드가 두개 이상이라면
    {
        Queue->Rear->NextNode = NewNode;// 후단의 다음노드는 대입하는 노드를 가리킨다
        Queue->Rear = NewNode;// 그리고 후단을 대입하는 노드로 만든다
        Queue->Count++;// 노드수가 증가함에따라 Count도 증가한다.
    }
}

Node* LQ_Dequeue( LinkedQueue* Queue )// 노드 제외
{
    //  LQ_Dequeue() 함수가 반환할 최상위 노드 
    Node* Front = Queue->Front;// 가장 앞의 노드로 지정

    if ( Queue->Front->NextNode == NULL )// 가장 앞의 다음노드가 Null이라면
    {
        Queue->Front = NULL;// 큐의 앞과 뒤를
        Queue->Rear  = NULL;// NULL로 지정
    }
    else
    {
        Queue->Front = Queue->Front->NextNode;// 그 외에는 모두 앞 노드를 한칸 땡겨준다. 개별적인 노드 헤제가 필요하다.
    }

    Queue->Count--;// 노드수가 감소함에 따라 Count도 감소한다.

    return Front;// 가장 앞의 노드를 반환해야한다.
}

int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL);// 만약 가장 전단 노드가 없다면 비어있다고 말할 수 있다.
}

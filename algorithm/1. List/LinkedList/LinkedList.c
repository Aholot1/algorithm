#include "LinkedList.h"//헤더 포함

//  노드 생성 
Node* SLL_CreateNode(ElementType NewData)//저장할 변수는 꼭 포인터로 선언하자.
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  //  데이터를 저장한다. 
    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화 한다. 

    return NewNode;//  노드의 주소를 반환한다. 
}

//  노드 소멸 
void SLL_DestroyNode(Node* Node)//저장해둔 노드 헤제.
{
    free(Node);// 노드 헤제
}

//  노드 추가 
void SLL_AppendNode(Node** Head, Node* NewNode)//머리 부분이 될 헤드 포인터의 주솟값을 줍니다.// 그리고 새로 추가할 노드를 줍니다. SLL_AppendNode(&List, NewNode);
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head 
    if ( (*Head) == NULL ) //헤드 노드가 nullptr 이라면, 새로 추가할 부분의 노드가 헤드로 지정
    {        
        *Head = NewNode;// 헤드 포인터의 주솟값을 새로운 노드의 주솟값으로 변경
    } 
    else// 아니라면
    {
        //  테일을 찾아 NewNode를 연결한다. 
        Node* Tail = (*Head);//꼬리부분을 찾기위한 변수
        while ( Tail->NextNode != NULL )//NULL이 아닐때까지 반복
        {
            Tail = Tail->NextNode;// 그 다음변수로 지정
        }// 여기까지 오면 다음 노드가 NULL이기에 그 포인터를 포함하고 있는 노드, 즉 꼬리부분이 Tail이 된다.

        Tail->NextNode = NewNode;//테일 부분의 다음을 가리키는 포인터에 새로운 노드의 주솟값 삽입 
    }
}

//  노드 삽입 
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void  SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ( Head == NULL )
    {
        (*Head) = NewHead;    
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode){ //Head = 헤드부분, Current = 현재로 지정한 위치의 노드, NewHead = ?
    Node* Previous = *Head;// 이전 위치 찾기
    while(Current != NULL && Previous->NextNode != Current){ // 이전위치 찾기 반복문
        Previous = Previous->NextNode;
    }

    if(Current == *Head){
        Previous->NextNode = *Head;
        *Head = Previous;

    }
    else{
        Previous->NextNode = NewNode;
        NewNode->NextNode = Current;
    }



}

//  노드 제거 
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ( *Head == Remove )
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while ( Current != NULL && Current->NextNode != Remove )
        {
            Current = Current->NextNode;
        }

        if ( Current != NULL )
            Current->NextNode = Remove->NextNode;
    }
}

//  노드 탐색 
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

//  노드 수 세기 
int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

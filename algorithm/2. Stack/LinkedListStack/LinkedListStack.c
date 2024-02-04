#include "LinkedListStack.h"

void  LLS_CreateStack( LinkedListStack** Stack ) //스택 생성
{
    //  스택을 자유 저장소에 생성 
    (*Stack )       = ( LinkedListStack*)malloc(sizeof( LinkedListStack ) );
    (*Stack )->List = NULL;
    (*Stack )->Top  = NULL;
}

void LLS_DestroyStack( LinkedListStack* Stack ) // 스택 파괴
{
    while ( !LLS_IsEmpty(Stack ) ) //만약 스택이 비어있지않다면
    {
        Node* Popped = LLS_Pop( Stack ); //최상위 노드를 걷어내고
        LLS_DestroyNode(Popped);    // 파괴 
    }// 스택이 비워질때까지 반복

    //  스택을 자유 저장소에서 해제 
    free(Stack );// 마지막으로 자신까지 자폭
}

Node* LLS_CreateNode( char* NewData )// 노드 생성
{
    Node* NewNode = ( Node*)malloc(sizeof( Node ) ); // 새로운 도르르 생성
    NewNode->Data = ( char*)malloc(strlen( NewData ) + 1);// 노드에 데이터에 NewData 길이 + 1(NULL문자) 만큼 할당

    strcpy( NewNode->Data, NewData ); //NewData의 값을 NewNode에 대입

    NewNode->NextNode = NULL; //  NewNode의 다음 노드는 Null 

    return NewNode;//  노드의 주소를 반환  
}

void  LLS_DestroyNode( Node* _Node )// 노드 파괴
{
    free(_Node->Data ); // 노드의 데이터도 동적할당이기에 헤제해줄 필요가 있다
    free(_Node ); // 노드 파괴까지 
}

void LLS_Push( LinkedListStack* Stack, Node* NewNode ) // 노드 삽입
{
    if ( Stack->List == NULL ) //만약 노드가 아무것도 없다면
    {        
        Stack->List = NewNode; //최하위에 NewNode 삽입
    } 
    else//만약 노드가 하나라도 차있다면
    {
        //  스택의 Top에 신규 노드를 연결한다.
        Stack->Top->NextNode = NewNode; //Top에 다음노드를 New노드와 연결
    }
    
    //  스택의 Top 필드에 새 노드의 주소를 등록한다. 
    Stack->Top = NewNode; //데이터가 스택에 하나 더 쌓였기때문에 새로운 노드로 최상위 노드 주소가 갱신 필요 
}

Node* LLS_Pop( LinkedListStack* Stack ) //  최상위 노드 걷어내기 
{
    //  LLS_Pop() 함수가 반환할 최상위 노드 저장 
    Node* TopNode = Stack->Top;


    if ( Stack->List == Stack->Top ) // 만약 스택이 하나밖에 없다면 
    {
        Stack->List = NULL; //제외
        Stack->Top  = NULL; //제외
    }
    else
    {
        // Top 아래에 있던 노드를 새로운 CurrentTop에 저장 
        Node* CurrentTop = Stack->List; // 최하위 노드 
        while ( CurrentTop != NULL && CurrentTop->NextNode != Stack->Top ) // Current->NextNode노드가 스택의 탑이 아닐때
        {
            CurrentTop = CurrentTop->NextNode; //노드 갱신
        }

        // CurrentTop을 Top에 저장
        Stack->Top = CurrentTop;//Stack의 현재 Top을 이전 노드로 갱신
        Stack->Top->NextNode = NULL;//Stack의 현재 Top을 Null로 초기화
    }

    return TopNode;//제외한 탑 반환
}

Node* LLS_Top( LinkedListStack* Stack ) // 최상위 노드 
{
    return Stack->Top; //최상위 노드 반환
}

int LLS_GetSize( LinkedListStack* Stack ) // 스택 노드 갯수 
{
    int    Count = 0;//갯수를 셀 변수
    Node*  Current = Stack->List;//Current를 최하위 노드로 초기화

    while ( Current != NULL )//Current가 Null일때까지
    {
        Current = Current->NextNode;//
        Count++;
    }//이렇게 되면 갯수만큼 반복

    return Count;// 갯수 반환 
}

int LLS_IsEmpty( LinkedListStack* Stack ) // 비어있는가? 
{
    return (Stack->List == NULL); // List는 맨 아랫 노드이기때문에 이게 없으면 비어있는것(스택의 장점이라고 볼 수 있음 )
}

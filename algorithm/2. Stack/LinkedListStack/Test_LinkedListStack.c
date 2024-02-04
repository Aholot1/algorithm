#include "LinkedListStack.h"

int main( void )
{
    int i= 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;//스택 선언

    LLS_CreateStack(&Stack);//스택 생성
    
    LLS_Push( Stack, LLS_CreateNode("abc") );//1층
    LLS_Push( Stack, LLS_CreateNode("def") );//2층
    LLS_Push( Stack, LLS_CreateNode("efg") );//3층
    LLS_Push( Stack, LLS_CreateNode("hij") );//4층

    Count = LLS_GetSize(Stack); //노드 갯수 저장
    printf( "Size: %d, Top: %s\n\n", //노드 갯수와 현재 Top노드의 데이터 출력
        Count, LLS_Top(Stack)->Data );

    for ( i=0; i<Count; i++ )//노드 갯수만큼 반복 4번
    {
        if ( LLS_IsEmpty(Stack) )// 만약 비어있다면
            break;// 탈출

        Popped = LLS_Pop( Stack );//최상위 노드 걷어내기&걷어낸 Top노드 저장

        printf( "Popped: %s, ", Popped->Data );// 걷어낸 노드 데이터 출력

        LLS_DestroyNode(Popped);// 제외된 노드 헤제

        if ( ! LLS_IsEmpty(Stack) ) //만약 위의 작업을 다 진행하고 비어있지 않다면 
        {
            printf( "Current Top: %s\n", LLS_Top(Stack)->Data );//현재 남아있는 Top를 제외하고 그 데이터 출력
        }
        else
        {
            printf( "Stack Is Empty.\n");//다 비었다고 공지
        }
    }

    LLS_DestroyStack(Stack);//스택까지 자폭 

    return 0;
}

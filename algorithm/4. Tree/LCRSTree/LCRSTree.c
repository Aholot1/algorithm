#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode( ElementType NewData )
{
    LCRSNode* NewNode = (LCRSNode*)malloc( sizeof(LCRSNode) );// 할당
    NewNode->LeftChild    = NULL;// 널로 초기화
    NewNode->RightSibling = NULL;// 널로 초기화
    NewNode->Data = NewData;// 데이터는 매개변수로 지정

    return NewNode;// 주솟값 반환
}

void LCRS_DestroyNode( LCRSNode* Node )// 노드 파괴
{
    free(Node);
}

void LCRS_DestroyTree( LCRSNode* Root )//트리 파괴
{
    if ( Root->RightSibling != NULL )
        LCRS_DestroyTree( Root->RightSibling );

    if ( Root->LeftChild != NULL )
        LCRS_DestroyTree( Root->LeftChild );

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode( Root );
}

void LCRS_AddChildNode( LCRSNode* Parent, LCRSNode *Child)// 노드 연결 
{
    if ( Parent->LeftChild == NULL )// 부모에 연결된 자식이 없다면
    {
        Parent->LeftChild = Child;// 직계
    }
    else //연결된 자식이 있다면
    {
        LCRSNode* TempNode = Parent->LeftChild;
        while ( TempNode->RightSibling != NULL )//마지막 형제노드까지 차장가서 
            TempNode = TempNode->RightSibling;// 형제노드에 연결

        TempNode->RightSibling = Child;        // 형제노드에 연결
    }
}

void LCRS_PrintTree( LCRSNode* Node, int Depth )// 트리 출력
{
    // 들여쓰기
    int i=0; 
    for ( i=0; i<Depth-1; i++ )// 
        printf("   "); // 공백 3칸

    if (Depth > 0) // 자식 노드 여부 표시
        printf("+--");
    
    // 노드 데이터 출력
    printf("%c\n", Node->Data); 

    if ( Node->LeftChild != NULL )
        LCRS_PrintTree(Node->LeftChild, Depth+1); //재귀 시스템 

    if ( Node->RightSibling != NULL )
        LCRS_PrintTree(Node->RightSibling, Depth);// 재귀 시스템 
}


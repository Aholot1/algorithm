#include "ExpressionTree.h"

ETNode* ET_CreateNode( ElementType NewData )
{
    ETNode* NewNode = (ETNode*)malloc( sizeof(ETNode) );
    NewNode->Left    = NULL;
    NewNode->Right   = NULL;
    NewNode->Data    = NewData;

    return NewNode;
}

void ET_DestroyNode( ETNode* Node )
{
    free(Node);
}

void ET_DestroyTree( ETNode* Root )
{
    if ( Root == NULL )
        return;

    ET_DestroyTree( Root->Left );
    ET_DestroyTree( Root->Right );
    ET_DestroyNode( Root );
}

void ET_PreorderPrintTree( ETNode* Node )
{
    if ( Node == NULL )
        return;

    printf( " %c", Node->Data );

    ET_PreorderPrintTree( Node->Left );
    ET_PreorderPrintTree( Node->Right );
}

void ET_InorderPrintTree( ETNode* Node )
{
    if ( Node == NULL )
        return;
    
    printf( "(" );
    ET_InorderPrintTree( Node->Left );

    printf( "%c", Node->Data );

    ET_InorderPrintTree( Node->Right );
    printf( ")" );
}

void ET_PostorderPrintTree( ETNode* Node )
{
    if ( Node == NULL )
        return;
    
    ET_PostorderPrintTree( Node->Left );
    ET_PostorderPrintTree( Node->Right );
    printf( " %c", Node->Data );
}

void ET_BuildExpressionTree( char* PostfixExpression, ETNode** Node ) //트리 방식으로 Node에 빌드// 매개변수는 후위표기로 된 문자열& 노드
{
    int  len        = strlen( PostfixExpression ); //수식 길이
    char Token      = PostfixExpression[ len -1 ]; // 가장 마지막 토큰
    PostfixExpression[ len-1 ] = '\0';// 마지막토큰 = \0으로 설정

    switch ( Token ) //토큰 인식
    {
        //  연산자인 경우 
        case '+': case '-': case '*': case '/': //연산자 집합!
            (*Node) = ET_CreateNode( Token );
            ET_BuildExpressionTree( PostfixExpression, &(*Node)->Right );
            ET_BuildExpressionTree( PostfixExpression, &(*Node)->Left  );
            break;

        //  피연산자인 경우 
        default :
            (*Node) = ET_CreateNode( Token);
            break;
    }
}

double ET_Evaluate( ETNode* Tree )// 뿌리를 준다.
{
    char Temp[2];
    
    double Left   = 0;
    double Right  = 0;
    double Result = 0;

    if ( Tree == NULL )
        return 0;

    switch ( Tree->Data ) 
    {
        //  연산자인 경우 
        case '+': case '-': case '*': case '/':
            Left  = ET_Evaluate( Tree->Left );
            Right = ET_Evaluate( Tree->Right );

                 if ( Tree->Data == '+' ) Result = Left + Right;
            else if ( Tree->Data == '-' ) Result = Left - Right;
            else if ( Tree->Data == '*' ) Result = Left * Right;
            else if ( Tree->Data == '/' ) Result = Left / Right;            

            break;

        //  피연산자인 경우 
        default :
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);  
            break;
    }

    return Result;
}

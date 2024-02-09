#ifndef LCRS_TREE_H //left child right sibling
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode 
{
    struct tagLCRSNode* LeftChild; //왼쪽 자손
    struct tagLCRSNode* RightSibling;// 오른쪽 형제

    ElementType Data;// 값
} LCRSNode;


LCRSNode* LCRS_CreateNode( ElementType NewData );// 노드 생성
void      LCRS_DestroyNode( LCRSNode* Node );// 노드파괴
void      LCRS_DestroyTree( LCRSNode* Root );// 

void      LCRS_AddChildNode( LCRSNode* ParentNode, LCRSNode *ChildNode);
void      LCRS_PrintTree( LCRSNode* Node, int Depth );

#endif

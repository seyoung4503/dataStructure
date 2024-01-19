
#include "RBT.h"

extern RBTNode* Nil;

void RBT_DestroyTree(RBTNode* Tree)
{
    if (Tree->Left != Nil)
        RBT_DestroyTree(Tree->Left);
    if (Tree->Right != Nil)
        RBT_DestroyTree(Tree->Right);
    
    Tree->Left = Nil;
    Tree->Right = Nil;

    RBT_DestroyNode(Tree);
}

RBTNode* RBT_CreateNode(ElementType NewData)
{
    RBTNode* NewNode = (RBTNode*)malloc( sizeof(RBTNode) );
    NewNode->Parent = NULL;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;
    NewNode->Color = BLACK;

    return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
    free(Node);
}

RBTNode* RBT_SearchNode(RBTNode * Tree, ElementType Target)
{
    if (Tree == Nil)
        return NULL;
    if (Tree->Data > Target)
        return RBT_SearchNode(Tree->Left, Target);
    else if (Tree->Data < Target)
        return RBT_SearchNode(Tree->Right, Target);
    else    
        return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
    if (Tree == Nil)
        return Nil;
    if (Tree->Left != Nil)
        return RBT_SearchMinNode(Tree->Left);
    else
        return Tree;
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
    if ((*Tree) == NULL)
        (*Tree) = NewNode;
    
    if ((*Tree)->Data < NewNode->Data)
    {
        if ((*Tree)->Right == Nil)
        {
            (*Tree)->Right = NewNode;
            NewNode->Parent = (*Tree);
        }
        else
            RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
    }
    else if ((*Tree)->Data > NewNode->Data)
    {
        if((*Tree)->Left == Nil)
        {
            (*Tree)->Left = NewNode;
            NewNode->Parent = (*Tree);
        }
        RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
    }
}

void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{

    while (X != (*Root) && X->Parent->Color == RED)
    {
        if (X->Parent == X->Parent->Parent->Left)
        {
            RBTNode* Uncle = X->Parent->Parent->Right;
            if (Uncle->Color == RED)
            {
                Uncle->Color = BLACK;
                X->Parent->Parent->Color = RED;
                X->Parent->Color = BLACK;
                X = X->Parent->Parent;
            }
            else 
            {
                if (X == X->Parent->Right)  // Uncle->Color == 'BLACK' && X == X->Parent->Right
                {
                    X = X->Parent;
                    RBT_RotateLeft(Root, X);
                }
                // Uncle->Color == 'BLACK' && X == X->Parent->Left
                X->Parent->Color = BLACK;
                X->Parent->Parent->Color = RED;
                RBT_RotateRight(Root, X->Parent->Parent);
            }
        }
        else
        {
            RBTNode* Uncle = X->Parent->Parent->Left;
            if (Uncle->Color == RED)
            {
                X->Parent->Color = BLACK;
                Uncle->Color = BLACK;
                X->Parent->Parent->Color = RED;
                X = X->Parent->Parent;
            }
            else
            {
                if (X == X->Parent->Left)
                {
                    X = X->Parent;
                    RBT_RotateRight(Root, X);
                }

                X->Parent->Color = BLACK;
                X->Parent->Parent->Color = RED;
                RBT_RotateLeft(Root, X->Parent->Parent);
            }
        }
    }
    (*Root)->Color = BLACK;
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
    RBT_InsertNodeHelper(Tree, NewNode);
    NewNode->Color = RED;
    NewNode->Left = Nil;
    NewNode->Right = Nil;
    RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
    RBTNode* LeftChild = Parent->Left;
    Parent->Left = LeftChild->Right;

    if (LeftChild->Right != Nil)
        LeftChild->Right->Parent = Parent;

    LeftChild->Parent = Parent->Parent;

    if (Parent->Parent == NULL)
        (*Root) = LeftChild;
    else 
    {
        if (Parent == Parent->Parent->Left)
            Parent->Parent->Left = LeftChild;
        else
            Parent->Parent->Right = LeftChild;
    }

    LeftChild->Right = Parent;
    Parent->Parent = LeftChild;

}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
    RBTNode* RightChild = Parent->Right;
    Parent->Right = RightChild->Left;

    if (RightChild->Left != Nil)
        RightChild->Left->Parent = Parent;

    RightChild->Parent = Parent->Parent;

    if (Parent->Parent == NULL)
        (*Root) = RightChild;
    else
    {
        if (Parent == Parent->Parent->Left)
            Parent->Parent->Left = RightChild;
        else
            Parent->Parent->Right = RightChild;
    }

    RightChild->Left = Parent;
    Parent->Parent = RightChild;
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{   
    RBTNode* Sibling = NULL;
    while (Successor->Parent != NULL && Successor->Color == BLACK)
    {
        if (Successor == Successor->Parent->Left)
        {   
            Sibling = Successor->Parent->Right;
            // no.1 p.262
            if (Sibling->Color == RED)
            {
                Successor->Parent->Color = RED;
                Sibling->Color = BLACK;
                RBT_RotateLeft(Root, Successor->Parent);
            }
            else 
            {
                // 2-A. p.263
                if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK)
                {
                    Sibling->Color = RED;
                    Successor = Successor->Parent;
                    // Successor의 Color가 RED일 경우 BLACK으로 수정(while 이후)
                    // Successor->Color가 원래 검은 색인 경우 이중 흑색은 어떻게 처리?
                }
                // 2-B p.264 형제 자식이 R, B 일 경우 if 문 조건 안에서 B, R으로 변함
                else
                {
                    if (Sibling->Left->Color == RED)
                    {
                        Sibling->Color = RED;
                        Sibling->Left->Color = BLACK;
                        RBT_RotateRight(Root, Sibling);
                        Sibling = Successor->Parent->Right;
                    }
                    // 2-C p.266 // 조건 명시 안한 이유는 2-B 조건에서 넘어오는 경우가 있음
                    Sibling->Color = Successor->Parent->Color;
                    Successor->Parent->Color = BLACK;
                    Sibling->Right->Color = BLACK;
                    RBT_RotateLeft(Root, Successor->Parent);
                    Successor = (*Root);
                }
            }
        }
        else // Left, Right 반전
        {
            Sibling = Successor->Parent->Left;
            // no.1 p.262
            if (Sibling->Color == RED)
            {
                Successor->Parent->Color = RED;
                Sibling->Color = BLACK;
                RBT_RotateRight(Root, Successor->Parent);
            }
            else 
            {
                // 2-A.
                if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK)
                {
                    Sibling->Color = RED;
                    Successor = Successor->Parent;
                }
                // 2-B 
                if (Sibling->Right->Color == RED)
                {
                    Sibling->Color = RED;
                    Sibling->Right->Color = BLACK;
                    RBT_RotateLeft(Root, Sibling);
                    Sibling = Successor->Parent->Left;
                }
                // 2-C p.266 // 조건 명시 안한 이유는 2-B 조건에서 넘어오는 경우가 있음
                Sibling->Color = Successor->Parent->Color;
                Successor->Parent->Color = BLACK;
                Sibling->Left->Color = BLACK;
                RBT_RotateRight(Root, Successor->Parent);
                Successor = (*Root);
            }
        }
    }
    Successor->Color = BLACK;
}

RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data)
{
    RBTNode* Removed = NULL;
    RBTNode* Successor = NULL;
    RBTNode* Target = RBT_SearchNode((*Root), Data);

    if (Target == NULL)
        return NULL;
    
    if (Target->Left == Nil || Target->Right == Nil)
        Removed = Target;

    else
    {
        Removed = RBT_SearchMinNode(Target->Right);
        Target->Data = Removed->Data;
    }

    if (Removed->Left == Nil)
        Successor = Removed->Right;
    else
        Successor = Removed->Left;

    Successor->Parent = Removed->Parent;

    if (Removed->Parent == NULL)
        (*Root) = Successor;
    else
    {
        if (Removed == Removed->Parent->Left)
            Removed->Parent->Left = Successor;
        else
            Removed->Parent->Right = Successor;
    }

    if (Removed->Color == BLACK)
        RBT_RebuildAfterRemove(Root, Successor);

    return Removed;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
    int i = 0;
    char c = 'X';
    int v = -1;
    char cnt[100];

    if (Node == NULL || Node == Nil)
        return;

    if (Node->Color == BLACK)
        BlackCount ++;
    
    if (Node ->Parent != NULL)
    {
        v = Node->Parent->Data;

        if (Node->Parent->Left == Node)
            c = 'L';
        else
            c = 'R';
    }

    if (Node->Left == Nil && Node->Right == Nil)
        sprintf(cnt, "-------- %d", BlackCount);
    else
        sprintf(cnt, "");
    
    for(i = 0; i < Depth; i++) 
        printf(" ");
    
    printf( "%d %s [%c, %d] %s\n", Node->Data, (Node->Color == RED)?"RED":"BLACK", c, v, cnt);

    RBT_PrintTree(Node->Left, Depth+1, BlackCount);
    RBT_PrintTree(Node->Right, Depth+1, BlackCount);

}
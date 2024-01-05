

// #define db printf("DEBUG")
#include "DLL.h"

Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;

    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

void DLL_AppendNode(Node ** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else 
    {
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

Node* DLL_GetNodeAt(Node * Head, int index)
{
    Node * Current = Head;

    while (Current != NULL && (--index) >= 0)
    {
        Current = Current->NextNode;
    }
    
    return Current;
}

void DLL_RemoveNode(Node ** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        if ((*Head) != NULL)
            (*Head)->PrevNode = NULL;
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;

        Remove->PrevNode->NextNode = Temp->NextNode;

        if (Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Temp->PrevNode;
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

void DLL_InsertAfter(Node * Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
    }
    Current->NextNode = NewNode;
}

void ListPrint(Node * head){
    Node* Tail = (head);
    
    while (Tail->NextNode != NULL)
    {
        printf("%d \n", Tail->Data);
        Tail = Tail->NextNode;
        
    }
    printf("%d \n", Tail->Data);
}
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode
{
    int Data;
    struct tagNode * PrevNode;
    struct tagNode * NextNode;
} Node;

typedef struct DLLStruct
{   
    void * headPtr;
    void * tailPtr;
    struct tagNode ** start; 
} DLLStruct;

void    DLLStruct_Create();
Node*   DLL_CreateNode(ElementType NewData);
void    DLL_AppendNode(Node ** Head, Node* NewNode);
Node*   DLL_GetNodeAt(Node * Head, int index);
void    DLL_RemoveNode(Node ** Head, Node* Remove);
void    DLL_InsertAfter(Node * Current, Node* NewNode);

void ListPrint(Node * head);




#endif
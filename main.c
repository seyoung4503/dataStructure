#include "DLL.h"
#include "ArrayStack.h"
#include "CircularQueue.h"
#include "LCRS.h"

int main()
{
    // DLL ex
    Node * List = NULL;
    Node * NewNode = NULL;
    
    NewNode = DLL_CreateNode(117);
    
    DLL_AppendNode(&List, NewNode);
    //ListPrint(List);

    NewNode = DLL_CreateNode(119);
    DLL_AppendNode(&List, NewNode);
    ListPrint(List);


    Node * List1 = NULL;
    NewNode = DLL_CreateNode(120);
    
    DLL_AppendNode(&List1, NewNode);
    //ListPrint(List);

    NewNode = DLL_CreateNode(121);
    DLL_AppendNode(&List1, NewNode);
    ListPrint(List1);

    // Stack ex
    int i = 0; 
    ArrayStack* Stack = NULL;
    AS_CreateStack(&Stack, 10);
    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);

    printf("%d, %d, %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    for (i = 0; i < 4; i++)
    {
        if (AS_IsEmpty(Stack))
            break;
        
        printf("pop! %d, ", AS_Pop(Stack));

        if (!AS_IsEmpty(Stack))
            printf("Cur Top : %d\n", AS_Top(Stack));
        else
            printf("Stack Empty!\n");
    }

    AS_DestroyStack(Stack);

    // Queue ex
    i = 0;
    CircularQueue* Queue;

    CQ_CreateQueue(&Queue, 10);

    CQ_EnQueue(Queue, 1);
    CQ_EnQueue(Queue, 2);
    CQ_EnQueue(Queue, 3);
    CQ_EnQueue(Queue, 4);

    for (i = 0; i < 3; i++)
    {
        printf("Dequeue %d, ", CQ_DeQueue(Queue));
        printf("Front %d, Rear %d\n", Queue->Front, Queue->Rear);
    }

    i = 100;
    while (CQ_IsFull(Queue) == 0)
    {
        CQ_EnQueue(Queue, i++);
    }

    printf("%d, %d\n\n", Queue->Capacity, CQ_GetSize(Queue));
    while (CQ_IsEmpty(Queue) == 0)
    {
        printf("Dequeue %d, ", CQ_DeQueue(Queue));
        printf("Front %d, Rear %d\n", Queue->Front, Queue->Rear);
    }

    CQ_DestroyQueue(Queue);


    // LCRS ex
    LCRSNode* Root = LCRS_CreateNode('A');

    LCRSNode* B = LCRS_CreateNode('B');
    LCRSNode* C = LCRS_CreateNode('C');
    LCRSNode* D = LCRS_CreateNode('D');
    LCRSNode* E = LCRS_CreateNode('E');
    LCRSNode* F = LCRS_CreateNode('F');
    LCRSNode* G = LCRS_CreateNode('G');
    LCRSNode* H = LCRS_CreateNode('H');
    LCRSNode* I = LCRS_CreateNode('I');
    LCRSNode* J = LCRS_CreateNode('J');
    LCRSNode* K = LCRS_CreateNode('K');

    LCRS_Add_ChildNode(Root, B);
    LCRS_Add_ChildNode(B, C);
    LCRS_Add_ChildNode(B, D);
    LCRS_Add_ChildNode(D, E);
    LCRS_Add_ChildNode(D, F);

    LCRS_Add_ChildNode(Root, G);
    LCRS_Add_ChildNode(G, H);

    LCRS_Add_ChildNode(Root, I);
    LCRS_Add_ChildNode(I, J);
    LCRS_Add_ChildNode(J, K);

    LCRS_PrintTree(Root, 0);

    LCRS_DestroyTree(Root);

    return 0;
}
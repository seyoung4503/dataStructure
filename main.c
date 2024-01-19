// #include "DLL.h"
// #include "ArrayStack.h"
// #include "CircularQueue.h"
// #include "LCRS.h"
// #include "BinaryTree.h"
#include "RBT.h"

RBTNode* Nil;

int main()
{
    // // DLL ex
    // Node * List = NULL;
    // Node * NewNode = NULL;
    
    // NewNode = DLL_CreateNode(117);
    
    // DLL_AppendNode(&List, NewNode);
    // //ListPrint(List);

    // NewNode = DLL_CreateNode(119);
    // DLL_AppendNode(&List, NewNode);
    // ListPrint(List);


    // Node * List1 = NULL;
    // NewNode = DLL_CreateNode(120);
    
    // DLL_AppendNode(&List1, NewNode);
    // //ListPrint(List);

    // NewNode = DLL_CreateNode(121);
    // DLL_AppendNode(&List1, NewNode);
    // ListPrint(List1);

    // // Stack ex
    // int i = 0; 
    // ArrayStack* Stack = NULL;
    // AS_CreateStack(&Stack, 10);
    // AS_Push(Stack, 3);
    // AS_Push(Stack, 37);
    // AS_Push(Stack, 11);
    // AS_Push(Stack, 12);

    // printf("%d, %d, %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    // for (i = 0; i < 4; i++)
    // {
    //     if (AS_IsEmpty(Stack))
    //         break;
        
    //     printf("pop! %d, ", AS_Pop(Stack));

    //     if (!AS_IsEmpty(Stack))
    //         printf("Cur Top : %d\n", AS_Top(Stack));
    //     else
    //         printf("Stack Empty!\n");
    // }

    // AS_DestroyStack(Stack);

    // // Queue ex
    // i = 0;
    // CircularQueue* Queue;

    // CQ_CreateQueue(&Queue, 10);

    // CQ_EnQueue(Queue, 1);
    // CQ_EnQueue(Queue, 2);
    // CQ_EnQueue(Queue, 3);
    // CQ_EnQueue(Queue, 4);

    // for (i = 0; i < 3; i++)
    // {
    //     printf("Dequeue %d, ", CQ_DeQueue(Queue));
    //     printf("Front %d, Rear %d\n", Queue->Front, Queue->Rear);
    // }

    // i = 100;
    // while (CQ_IsFull(Queue) == 0)
    // {
    //     CQ_EnQueue(Queue, i++);
    // }

    // printf("%d, %d\n\n", Queue->Capacity, CQ_GetSize(Queue));
    // while (CQ_IsEmpty(Queue) == 0)
    // {
    //     printf("Dequeue %d, ", CQ_DeQueue(Queue));
    //     printf("Front %d, Rear %d\n", Queue->Front, Queue->Rear);
    // }

    // CQ_DestroyQueue(Queue);


    // // // LCRS ex
    // // LCRSNode* Root = LCRS_CreateNode('A');

    // // LCRSNode* B = LCRS_CreateNode('B');
    // // LCRSNode* C = LCRS_CreateNode('C');
    // // LCRSNode* D = LCRS_CreateNode('D');
    // // LCRSNode* E = LCRS_CreateNode('E');
    // // LCRSNode* F = LCRS_CreateNode('F');
    // // LCRSNode* G = LCRS_CreateNode('G');
    // // LCRSNode* H = LCRS_CreateNode('H');
    // // LCRSNode* I = LCRS_CreateNode('I');
    // // LCRSNode* J = LCRS_CreateNode('J');
    // // LCRSNode* K = LCRS_CreateNode('K');

    // // LCRS_Add_ChildNode(Root, B);
    // // LCRS_Add_ChildNode(B, C);
    // // LCRS_Add_ChildNode(B, D);
    // // LCRS_Add_ChildNode(D, E);
    // // LCRS_Add_ChildNode(D, F);

    // // LCRS_Add_ChildNode(Root, G);
    // // LCRS_Add_ChildNode(G, H);

    // // LCRS_Add_ChildNode(Root, I);
    // // LCRS_Add_ChildNode(I, J);
    // // LCRS_Add_ChildNode(J, K);

    // // LCRS_PrintTree(Root, 0);

    // // LCRS_DestroyTree(Root);

    // SBTNode* A = SBT_CreateNode('A');
    // SBTNode* B = SBT_CreateNode('B');
    // SBTNode* C = SBT_CreateNode('C');
    // SBTNode* D = SBT_CreateNode('D');
    // SBTNode* E = SBT_CreateNode('E');
    // SBTNode* F = SBT_CreateNode('F');
    // SBTNode* G = SBT_CreateNode('G');

    // A->Left = B;
    // B->Left = C;
    // B->Right = D;

    // A->Right = E;
    // E->Left = F;
    // E->Right = G;

    // printf("Preorder ...\n");
    // SBT_PreorderPrintTree(A);
    // printf("\n\n");

    // printf("Inorder ...\n");
    // SBT_InorderPrintTree(A);
    // printf("\n\n");

    // printf("Postorder ...\n");
    // SBT_PostorderPrintTree(A);
    // printf("\n\n");

    // SBT_DestroyTree(A);


    // RBT ex
    RBTNode* Tree = NULL;
    RBTNode* Node = NULL;

    Nil = RBT_CreateNode(0);
    Nil->Color = BLACK;

    while (1)
    {
        int cmd = 0;
        int param = 0;
        char buffer[10];

        RBTNode* debug = NULL;

        printf("Enter command number : \n");
        printf("(1) Create a node, (2) Remove a node, (3) Search a node, (4) Display Tree, (5) Quit\n");
        printf("Command number : ");

        fgets(buffer, sizeof(buffer)-1, stdin);
        sscanf(buffer, "%d", &cmd);

        if (cmd < 1 || cmd > 5)
        {
            printf("Invalid command number.\n");
            continue;
        }
        else if (cmd == 4)
        {
            RBT_PrintTree(Tree, 0, 0);
            printf("\n");
            continue;
        }
        else if (cmd == 5)
            break;

        printf("Enter param (1~200)\n");

        fgets(buffer, sizeof(buffer)-1, stdin);
        sscanf(buffer, "%d", &param);

        if (param < 1 || param > 200)
        {
            printf("Invalid param. %d\n", param);
            continue;
        }

        switch (cmd)
        {
            case 1:
                // debug = RBT_CreateNode(param);
                // printf("debug %d", debug->Data);
                RBT_InsertNode(&Tree, RBT_CreateNode(param));
                break;

            case 2:
                Node = RBT_RemoveNode(&Tree, param);

                if (Node == NULL)
                    printf("NOT FOUND, %d", param);
                else
                    RBT_DestroyNode(Node);
                
                break;
            
            case 3:
                Node = RBT_SearchNode(Tree, param);

                if (Node == NULL)
                    printf("NOT FOUND, %d", param);
                else
                    printf( "FOUND NODE : %d(Color:%s)\n", Node->Data, (Node->Color == RED)?"RED":"BLACK");
                
                break;
            
            printf("\n");

        }
    }
    RBT_DestroyTree(Tree);
    return 0;
}
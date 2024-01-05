#include "linkedlist.h"

int main() {
    DLL *mylistPtr = NULL;
    ListAppend(&mylistPtr, 0, 0);
    ListAppend(&mylistPtr, 1, 1);
    ListAppend(&mylistPtr, 2, 2);
    ListAppend(&mylistPtr, 3, 3);
    ListPrint(&mylistPtr);




//     //ListNode * myList = NULL;
    
//     ListAppend(&myList, 0, 0);
//     ListAppend(&myList, 1, 1);
//     ListAppend(&myList, 2, 2);
//     ListAppend(&myList, 3, 3);


//     ListPrint(&myList);
//     printf("\n");

//     ListDelete(&myList, 3);
//     ListDelete(&myList, 1);
//     ListPrint(&myList);


//     ListNode * myList2 = NULL;
    
//     ListAppend(&myList2, 0, 4);
//     ListAppend(&myList2, 1, 5);
//     ListAppend(&myList2, 2, 6);
//     ListAppend(&myList2, 3, 7);


//     ListPrint(&myList2);
//     printf("\n");

//     ListDelete(&myList2, 3);
//     ListDelete(&myList2, 1);
//     ListPrint(&myList2);
    return 0;
}
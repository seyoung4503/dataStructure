
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE 
{
    int index;
    int data;
    struct NODE* prev;
    struct NODE* next;

} ListNode;

// // struct NODE * head;
// struct NODE * tail;
// extern int size;

typedef struct DoubleLinkedList
{
    struct NODE * head;
    struct NODE * tail;
    struct NODE * start;
    int size;
}DLL;


void ListAppend(DLL* first, int index, int item);
void ListPrint(DLL* first);
void List_Delete(DLL* first, ListNode * node);
void ListDelete(DLL* first, int index);
void ListSort();
int getNodeIndex();

#endif
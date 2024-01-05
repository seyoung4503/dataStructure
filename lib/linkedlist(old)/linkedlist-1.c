#include "linkedlist.h"

void initList(DLL* first)
{
    struct NODE * head = first->head;
    struct NODE * tail = first->tail;
    int size = first->size;
}

void ListAppend(DLL* first, int index, int item){

    struct NODE * head = first->head;
    struct NODE * tail = first->tail;
    int size = first->size;
    
    int nodeIndex = index;
    struct NODE * prev_node = head;
    while(nodeIndex-1 > 0)
    {
        prev_node = prev_node->next;
        nodeIndex--;
    }

    ListNode * new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;


    if(index == 0 && head == NULL) 
    {
        head = new_node;
        tail = new_node;
        size = 0;
    } 
    else if(index == 0) 
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if(index == size) 
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = prev_node->next;
        new_node->prev = prev_node;

        prev_node->next->prev = new_node;
        prev_node->next = new_node;
    }
    size++;
}

void ListPrint(DLL* first){

    struct NODE * head = first->head;
    struct NODE * tail = first->tail;
    int size = first->size;

    int ListSize = size;
    ListNode * node = head;
    while(ListSize) 
    {
        printf("%d\n", node->data);
        node = node->next;
        ListSize--;
    }
}

void List_Delete(DLL* first, ListNode * node) 
{
    struct NODE * head = first->head;
    struct NODE * tail = first->tail;
    int size = first->size;

    if(head == node && tail == node) 
    {
        head = NULL;
        tail = NULL;
        free(node);
    } 
    else if(head == node) 
    {
        node->next->prev = NULL;
        head = node->next;
        free(node);
    }
    else if(tail == node) 
    {
        node->prev->next = NULL;
        tail = node->prev;
        free(node);
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    size--;
}

void ListDelete(DLL* first, int index) 
{
    struct NODE * head = first->head;
    struct NODE * tail = first->tail;
    int size = first->size;
    
    int nodeIndex = index;
    struct NODE * delete_node = head;
    while(nodeIndex > 0)
    {
        delete_node = delete_node->next;
        nodeIndex--;
    }
    List_Delete(first, delete_node);

}

void ListSort() 
{

}
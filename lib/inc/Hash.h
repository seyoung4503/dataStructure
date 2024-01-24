

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType; // int 이외의 다른 값이 될 수 있나?-> 가능 Key로 리스트에 접근하지 않는다. 대신 main에서 그에 맞는 타입으로 입력해야 함
typedef int ValueType;

typedef struct tagNode
{
    KeyType Key;
    ValueType Value;
} Node;

typedef struct tagHashTable
{
    int TableSize;
    Node* Table;
} HashTable;

HashTable* CreateHashTable(int TableSize);
void HT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType HT_Get(HashTable* HT, KeyType Key);
void HT_DestroyHashTable(HashTable* HT);
int Hash(KeyType Key, int KeyLength, int TableSize);

#endif
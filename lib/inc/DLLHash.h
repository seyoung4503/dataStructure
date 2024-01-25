

#ifndef DLLHASHTABLE_H
#define DLLHASHTABLE_H

// 이 예제는 DLL을 사용해서 해시 함수를 구현한다면 더 좋은 성능을 낼 것이라고 기대하지 않는다. 
// 다만, 코드의 재사용성에 있어 더 어려운 코드를 맞추기 전의 연습에 의의를 두었다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLL.h"

typedef char* KeyType; // int 이외의 다른 값이 될 수 있나?-> 가능 Key로 리스트에 접근하지 않는다. 대신 main에서 그에 맞는 타입으로 입력해야 함
typedef ElementType ValueType;

// struct는 부모 클래스의 재사용성 없이 다시 선언했지만, 부모 클래스의 함수들은 사용할 수 있을 것.
typedef struct tagHashNode
{
    KeyType Key;
    ValueType Value;
    // Key를 해시 함수에 넣은 값을 주소로 사용
    
    // DLL 노드 추가
    struct tagHashNode* prev;
    struct tagHashNode* next;
} HashNode;

typedef HashNode* List;

typedef struct tagHashTable
{
    int TableSize;
    List* Table;
} HashTable;

HashTable* CreateHashTable(int TableSize);
void HT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType HT_Get(HashTable* HT, KeyType Key);
void HT_DestroyHashTable(HashTable* HT);
int Hash(KeyType Key, int KeyLength, int TableSize);

#endif
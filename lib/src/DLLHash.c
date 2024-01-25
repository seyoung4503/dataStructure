
#include "DLLHash.h"

HashTable* CreateHashTable(int TableSize)
{   
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->Table = (List*)malloc(sizeof(List)*TableSize);

    HT->TableSize = TableSize;

    memset(HT->Table, 0, sizeof(List)*TableSize);

    return HT;
}

HashNode* CHT_CreateNode(KeyType Key, ValueType Value)
{
    HashNode* NewNode = (HashNode*)malloc(sizeof(HashNode));
    Node* DLLNode = NULL;
    DLL_CreateNode();

    NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key)+1));
    strcpy(NewNode->Key, Key);
    NewNode->DLL_Hash = 

    return NewNode;

}

void CHT_DestroyNode(HashNode * node)
{
    free(node->Key);
    free(node->Value);
    free(node);
}

void HT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
    int Address = Hash(Key, strlen(Key), HT->TableSize);
    HashNode* NewNode = CHT_CreateNode(Key, Value);

    List ListNode = HT->Table[Address];
    // List Target = NULL;

    if (ListNode != NULL)
    {
        NewNode->Next = ListNode;
        printf("collision occured : key(%s), address(%d)\n", Key, Address);
    }

    HT->Table[Address] = NewNode; // HT와 List node간 주소 연결


    int Address = Hash(Key, strlen(Key), HT->TableSize);
    List ListNode = HT->Table[Address];

    if (ListNode->DLL_Hash == NULL)
    {

    }


}

ValueType HT_Get(HashTable* HT, KeyType Key)
{
    int Address = Hash(Key, strlen(Key), HT->TableSize);

    List ListNode = HT->Table[Address];
    List Target = NULL;

    while (ListNode != NULL)
    {
        KeyType presentKey = ListNode->Key;
        if (strcmp(presentKey, Key) == 0)
        {
            Target = ListNode;
            break;
        }
        ListNode = ListNode->Next;
    }
    if (ListNode == NULL)  return NULL;
    return Target->Value;
}

void HT_DestroyList(List L)
{
    if (L == NULL)  return;
    if (L->Next != NULL) HT_DestroyList(L->Next);

    CHT_DestroyNode(L);
}

void HT_DestroyHashTable(HashTable* HT)
{
    int i = 0;
    for (i = 0; i < HT->TableSize; i++)
    {
        List L = HT->Table[i];
        HT_DestroyList(L);
    }
    free(HT->Table);
    free(HT);
}

int Hash(KeyType Key, int KeyLength, int TableSize)
{
    int i = 0;
    int HashValue = 0;
    for (i = 0; i < KeyLength; i++)
    {   
        HashValue = (HashValue<<3) + Key[i];
    }

    HashValue %= TableSize;

    return HashValue;
}


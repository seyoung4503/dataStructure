
#include "Hash.h"

HashTable* CreateHashTable(int TableSize)
{   
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->TableSize = TableSize;
    HT->Table = (Node*)malloc(sizeof(Node)*TableSize);

    return HT;
}

void HT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
    int Address = Hash(Key, strlen(Key), HT->TableSize);

    HT->Table[Address].Key = Key;
    HT->Table[Address].Value = Value;
}

ValueType HT_Get(HashTable* HT, KeyType Key)
{
    int Address = Hash(Key, strlen(Key), HT->TableSize);
    return HT->Table[Address].Value;
}

void HT_DestroyHashTable(HashTable* HT)
{
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

    return HashValue;
}


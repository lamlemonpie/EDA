//
//  hashTable.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef hashTable_h
#define hashTable_h

#include "hashNode.h"
const int TABLE_SIZE = 80000;

template<class T, class U>
class HashTable
{
private:
    HashNode<T,U>** m_hMap;
public:
    HashTable(){
        m_hMap = new HashNode<T,U>*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            m_hMap[i] = NULL;
    }
    ~HashTable(){
        for (int i = 0; i < TABLE_SIZE; ++i){
            HashNode<T,U>* entry    = m_hMap[i];
            while (entry != NULL){
                HashNode<T,U>* prev = entry;
                entry               = entry->m_pNext;
                delete prev;
            }
        }
        delete[] m_hMap;
    }
    
    //Función hash.
    int HashFunc(T key){
        return key % TABLE_SIZE;
    }
    
    //Insertar elemento.
    bool insert(T key, U value){
        int hash_val         = HashFunc(key);
        HashNode<T,U>* prev  = NULL;
        HashNode<T,U>* entry = m_hMap[hash_val];
        while (entry != NULL){
            prev  = entry;
            entry = entry->m_pNext;
        }
        if (entry == NULL){
            entry = new HashNode<T,U>(key, value);
            if (prev == NULL) m_hMap[hash_val] = entry;
            else              prev->m_pNext    = entry;
        }
        else    entry->m_value = value;
        return false;
    }
    
    //Buscar elemento
    bool search(T key,U value){
        int hash_val         = HashFunc(key);
        HashNode<T,U>* entry = m_hMap[hash_val];
        while (entry != NULL){
            if (entry->m_key == key && entry->m_value == value) return true;
            entry = entry->m_pNext;
        }
        return false;
    }
    
    //Eliminar elemento.
    bool remove(T key)
    {
        int hash_val         = HashFunc(key);
        HashNode<T,U>* entry = m_hMap[hash_val];
        HashNode<T,U>* prev  = NULL;
        if (entry == NULL || entry->key != key) return false;
        while (entry->m_pNext != NULL){
            prev = entry;
            entry = entry->m_pNext;
        }
        if (prev != NULL)   prev->m_pNext = entry->m_pNext;
        delete entry;
        return true;
    }
};


#endif /* hashTable_h */

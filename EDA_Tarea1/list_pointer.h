//
//  list_pointer.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef list_pointer_h
#define list_pointer_h


#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class List_Pointer {
    Node<T> * m_pHead, * m_pTail;
public:
    List_Pointer();
    ~List_Pointer();
    
    void print();
    bool find(T data);
    void insert_Front(T data);
    void insert_Back(T data);
    void insert_Position(unsigned long pos,T data);
    void delete_Front();
    void delete_Back();
    void delete_Position(unsigned long pos);
};

template<class T>
List_Pointer<T>::List_Pointer(){
    m_pHead = m_pTail = NULL;
}

template<class T>
List_Pointer<T>::~List_Pointer(){
    cout << "LISTA ELIMINADA" << endl;
}

template <class T>
void List_Pointer<T>::print(){
    Node<T> * it = m_pHead;
    //cout << "IMPRIMIENDO LISTA" << endl;
    while(it != NULL){
        cout << " - " << it -> m_data;
        it = it -> m_pNext;
    }
    cout << " - " << endl;
}

template <class T>
bool List_Pointer<T>::find(T data){
    Node<T> * it = m_pHead;
    while(it != NULL){
        if(it->m_data == data) return true;
        it = it->m_pNext;
    }
    return false;
}

//Si está vacío, el nuevo será cabeza y cola
//Si no está vacío, guardamos la cabeza en un temporal,
//asignamos como nueva cabeza al nuevo y apuntamos a
//la anterior cabeza como el siguiente.
template <class T>
void List_Pointer<T>::insert_Front(T data){
    Node<T> * new_tmp   = new Node<T>(data);
    if(m_pHead == NULL){
        m_pHead = new_tmp;
        m_pTail = new_tmp;
    }
    else{
        new_tmp->m_pNext = m_pHead;
        m_pHead          = new_tmp;
    }
}

template <class T>
void List_Pointer<T>::insert_Back(T data){
    Node<T> * new_tmp = new Node<T>(data);
    if(m_pTail == NULL){
        m_pTail = new_tmp;
        m_pHead = new_tmp;
    }
    else{
        m_pTail->m_pNext = new_tmp;
        m_pTail          = new_tmp;
    }
}

template <class T>
void List_Pointer<T>::insert_Position(unsigned long pos, T data){
    Node<T> * previous_it   = NULL;
    Node<T> * it            = m_pHead;
    Node<T> * new_tmp       = new Node<T>(data);
    unsigned long count     = 0;
    while(it != NULL){
        if(count == pos){
            if(previous_it != NULL) previous_it->m_pNext = new_tmp;
            if(it == m_pHead)       m_pHead = new_tmp;
            if(it == m_pTail)       m_pTail = new_tmp;
            new_tmp->m_pNext = it;
            break;
        }
        previous_it  = it;
        it           = it->m_pNext;
        ++count;
    }
}

template <class T>
void List_Pointer<T>::delete_Front(){
    Node<T> * tmp = m_pHead;
    if(m_pHead == m_pTail) m_pTail = m_pHead->m_pNext;
    m_pHead = m_pHead->m_pNext;
    delete tmp;
}

template <class T>
void List_Pointer<T>::delete_Back(){
    Node<T> * previous_it = NULL;
    Node<T> * it          = m_pHead;
    while(it != m_pTail){
        previous_it = it;
        it          = it->m_pNext;
    }
    if(previous_it){
        m_pTail              = previous_it;
        previous_it->m_pNext = NULL;
    }
    else{
        m_pHead = it->m_pNext;
        m_pTail = it->m_pNext;
    }
    delete it;
}

template <class T>
void List_Pointer<T>::delete_Position(unsigned long pos){
    Node<T> * previous_it   = NULL;
    Node<T> * it            = m_pHead;
    unsigned long count     = 0;
    while(it != NULL){
        if(count == pos){
            if(previous_it != NULL) previous_it->m_pNext = it->m_pNext;
            if(it == m_pHead) m_pHead = it->m_pNext;
            if(it == m_pTail) m_pTail = previous_it;
            delete it;
            break;
        }
        previous_it = it;
        it          = it->m_pNext;
        ++count;
    }
}

#endif /* list_pointer_h */

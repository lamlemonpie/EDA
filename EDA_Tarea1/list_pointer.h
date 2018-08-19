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

template <class T>
class List_Pointer {
    Node<T> * m_pHead, * m_pTail;
public:
    List_Pointer();
    ~List_Pointer();
    
    void print();
    void insert_Front(T data);
    void insert_Back(T data);
    void insert_Position(unsigned long pos,T data);
    bool find(T data);
    void delete_Element(T data);
    
};

template<class T>
List_Pointer<T>::List_Pointer(){
    m_pHead = NULL;
    m_pTail = NULL;
}

template<class T>
List_Pointer<T>::~List_Pointer(){
    cout << "LISTA ELIMINADA" << endl;
}

template <class T>
void List_Pointer<T>::print(){
    
    Node<T> * it = m_pHead;
    cout << "IMPRIMIENDO LISTA" << endl;
    while(it != NULL)
    {
        cout << " - " << it -> data;
        it = it -> m_pNext;
    }
    cout << endl;
}


template <class T>
void List_Pointer<T>::insert_Front(T data){
    
    Node<T> * new_tmp   = new Node<T>();
    new_tmp -> data     = data;
    
    //Si está vacío, el nuevo será cabeza y cola
    if(m_pHead == NULL){
        m_pHead = new_tmp;
        m_pTail = new_tmp;
    }
    //Si no está vacío, guardamos la cabeza en un temporal,
    //asignamos como nueva cabeza al nuevo y apuntamos a
    //la anterior cabeza como el siguiente.
    else{
        Node<T> * tmp       = m_pHead;
        m_pHead             = new_tmp;
        m_pHead -> m_pNext  = tmp;
    }
}


template <class T>
void List_Pointer<T>::insert_Back(T data){
    Node<T> * new_tmp = new Node<T>();
    new_tmp -> data = data;
    
    if(m_pTail == NULL){
        m_pTail = new_tmp;
        m_pHead = new_tmp;
    }
    else{
        Node<T> * tmp   = m_pTail;
        m_pTail         = new_tmp;
        tmp -> m_pNext  = m_pTail;
    }
}


template <class T>
bool List_Pointer<T>::find(T data){
    Node<T> * it = m_pHead;
    while(it != NULL)
    {
        if(it->data == data)
            return true;
        it = it->m_pNext;
    }
    return false;
}

template <class T>
void List_Pointer<T>::insert_Position(unsigned long pos, T data){
    
}

#endif /* list_pointer_h */

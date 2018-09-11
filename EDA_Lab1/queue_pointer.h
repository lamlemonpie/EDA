//
//  queue_pointer.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef queue_pointer_h
#define queue_pointer_h

#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class Queue_Pointer {
    Node<T> * m_pHead, * m_pTail;
public:
    Queue_Pointer();
    ~Queue_Pointer();
    
    void print();
    bool isEmpty();
    void push(T data);
    T    pop();
    T    front();
};

template <class T>
Queue_Pointer<T>::Queue_Pointer(){
    m_pHead = m_pTail = NULL;
}

template <class T>
Queue_Pointer<T>::~Queue_Pointer(){
    cout << "COLA ELIMINADA" << endl;
}

template <class T>
void Queue_Pointer<T>::print(){
    Node<T> * it = m_pHead;
    //cout << "IMPRIMIENDO COLA" << endl;
    while(it != NULL){
        cout << " - " << it -> m_data;
        it = it -> m_pNext;
    }
    cout << " - " << endl;
}

template <class T>
bool Queue_Pointer<T>::isEmpty(){
    if(m_pHead)
        return false;
    return true;
}

template <class T>
void Queue_Pointer<T>::push(T data){
    Node<T> * new_tmp = new Node<T>(data);
    if(m_pHead != NULL) m_pTail->m_pNext = new_tmp;
    else                m_pHead = new_tmp;
    m_pTail = new_tmp;
}

template <class T>
T Queue_Pointer<T>::pop(){
    if(m_pHead != NULL){
        Node<T> * tmp = m_pHead;
        m_pHead       = m_pHead->m_pNext;
        T val         = tmp->m_data;
        delete tmp;
        return val;
    }
    return NULL;
}

template <class T>
T Queue_Pointer<T>::front(){
    if(m_pHead != NULL)
        return m_pHead -> m_data;
    return NULL;
}

#endif /* queue_pointer_h */

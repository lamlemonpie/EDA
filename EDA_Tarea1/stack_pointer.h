//
//  stack_pointer.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef stack_pointer_h
#define stack_pointer_h

#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class Stack_Pointer {
    Node<T> * m_pTop;
public:
    Stack_Pointer(){
        m_pTop = NULL;
    }
    
    void print();
    bool isEmpty();
    void push(T data);
    T pop();
    T top();
};

template <class T>
void Stack_Pointer<T>::print(){
    Node<T> * it = m_pTop;
    //cout << "IMPRIMIENDO COLA" << endl;
    while(it != NULL){
        cout << " - " << it -> m_data;
        it = it -> m_pNext;
    }
    cout << " - " << endl;
}

template <class T>
bool Stack_Pointer<T>::isEmpty(){
    if(m_pTop)
        return false;
    return true;
}

template <class T>
void Stack_Pointer<T>::push(T data){
    Node<T> *new_tmp = new Node<T>(data);
    if(m_pTop ==NULL){
        m_pTop = new_tmp;
    }
    else{
        new_tmp -> m_pNext = m_pTop;
        m_pTop             = new_tmp;
    }
}

template <class T>
T Stack_Pointer<T>::pop()
{
    if(m_pTop != NULL){
        Node<T> *tmp = m_pTop;
        m_pTop       = m_pTop->m_pNext;
        T val        = tmp->m_data;
        delete tmp;
        return val;
    }
    return NULL;
}

template <class T>
T Stack_Pointer<T>::top()
{
    return m_pTop->m_data;
}

#endif /* stack_pointer_h */

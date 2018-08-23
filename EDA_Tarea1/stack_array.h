//
//  stack_array.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef stack_array_h
#define stack_array_h

#include <iostream>

using namespace std;

template <class T>
class Stack_Array {
    T *m_stack;
    long          m_top;
    unsigned long m_maxSize;
public:
    Stack_Array();
    ~Stack_Array();
    
    void print();
    bool isEmpty();
    bool isFull();
    void push(T data);
    T    pop();
    T    top();
};

template <class T>
Stack_Array<T>::Stack_Array(){
    m_top       = -1;
    m_maxSize   = 10;
    m_stack     = new T[m_maxSize];
}

template <class T>
Stack_Array<T>::~Stack_Array(){
    cout << "PILA ELIMINADA" << endl;
}

template <class T>
void Stack_Array<T>::print(){
    for (auto i = 0; i <= m_top; ++i)
        cout << " - " << m_stack[i];
    cout << " - " << endl;
}

template <class T>
bool Stack_Array<T>::isEmpty(){
    if(m_top == -1) return true;
    return false;
}

template <class T>
bool Stack_Array<T>::isFull(){
    if(m_top+1 == m_maxSize) return true;
    return false;
}

template <class T>
void Stack_Array<T>::push(T data){
    if(isFull())
    {
        m_maxSize    = m_maxSize + (floor(m_maxSize/2));
        T *new_stack = new T[m_maxSize];
        for(unsigned long i = 0; i<=m_top; ++i)
            new_stack[i] = m_stack[i];
        m_stack      = new_stack;
    }
    ++m_top;
    m_stack[m_top] = data;
}

template <class T>
T Stack_Array<T>::pop(){
    T val = m_stack[m_top];
    --m_top;
    return val;
}

template <class T>
T Stack_Array<T>::top(){
    return m_stack[m_top];
}

#endif /* stack_array_h */

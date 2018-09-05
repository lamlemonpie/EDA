//
//  queue_array.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef queue_array_h
#define queue_array_h

#include <iostream>

using namespace std;

template <class T>
class Queue_Array {
    T *m_Queue;
    long          m_last;
    unsigned long m_maxSize;
public:
    Queue_Array();
    ~Queue_Array();
    
    void print();
    bool isEmpty();
    bool isFull();
    void push(T data);
    T    pop();
    T    front();
};

template <class T>
Queue_Array<T>::Queue_Array(){
    m_last      = -1;
    m_maxSize   = 10;
    m_Queue     = new T[m_maxSize];
}

template <class T>
Queue_Array<T>::~Queue_Array(){
    cout << "COLA ELIMINADA" << endl;
}

template <class T>
void Queue_Array<T>::print(){
    for (auto i = 0; i <= m_last; ++i)
        cout << " - " << m_Queue[i];
    cout << " - " << endl;
}

template <class T>
bool Queue_Array<T>::isEmpty(){
    if(m_last == -1) return true;
    return false;
}

template <class T>
bool Queue_Array<T>::isFull(){
    if(m_last+1 == m_maxSize) return true;
    return false;
}

template <class T>
void Queue_Array<T>::push(T data){
    if(isFull())
    {
        m_maxSize    = m_maxSize + (floor(m_maxSize/2));
        T *new_queue = new T[m_maxSize];
        for(unsigned long i = 0; i<=m_last; ++i)
            new_queue[i] = m_Queue[i];
        m_Queue      = new_queue;
    }
    ++m_last;
    m_Queue[m_last] = data;
}

template <class T>
T Queue_Array<T>::pop(){
    T val = m_Queue[0];
    for(unsigned long i = 0; i<=m_last; ++i)
        m_Queue[i] = m_Queue[i+1];
    --m_last;
    return val;
}

template <class T>
T Queue_Array<T>::front(){
    return m_Queue[0];
}

#endif /* queue_array_h */

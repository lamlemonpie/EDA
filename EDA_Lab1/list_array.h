//
//  list_array.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef list_array_h
#define list_array_h

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class List_Array {
    T *m_list;
    unsigned long m_begin;
    unsigned long m_length;
    unsigned long m_maxSize;
public:
    List_Array();
    ~List_Array();
    
    void print();
    bool isEmpty();
    bool isFrontFull();
    bool isBackFull();
    bool find(T data);
    void insert_Front(T data);
    void insert_Back(T data);
    void insert_Position(unsigned long pos,T data);
    void replace_Position(unsigned long pos, T data);
    T    retrieve_Position(unsigned long pos);
    void delete_Front();
    void delete_Back();
    void delete_Position(unsigned long pos);
    T*   update_list(unsigned long begin, T *&new_list);
};

template <class T>
List_Array<T>::List_Array(){
    
    m_length  = 0;
    m_maxSize = 10;
    m_begin   = floor(m_maxSize/2)-1;
    m_list    = new T[m_maxSize];
}

template <class T>
List_Array<T>::~List_Array(){
    cout << "LISTA ELIMINADA" << endl;
}

template <class T>
void List_Array<T>::print(){
    unsigned long size = m_begin + m_length;
    for (auto i = m_begin; i < size; ++i)
        cout << " - " << m_list[i];
    cout << " - " << endl;
}

template <class T>
bool List_Array<T>::isEmpty(){
    if(m_length == 0)
        return true;
    return false;
}

template <class T>
bool List_Array<T>::isFrontFull(){
    if(m_begin == 0) return true;
    return false;
}

template <class T>
bool List_Array<T>::isBackFull(){
    if((m_begin + m_length+1) == m_maxSize)
        return true;
    return false;
}

template <class T>
bool List_Array<T>::find(T data){
    unsigned long size = m_begin+m_length;
    for (unsigned long i = m_begin; i<size; ++i){
        if(m_list[i] == data)
            return true;
    }
    return false;
}

template <class T>
void List_Array<T>::insert_Front(T data){
    if(isFrontFull()){
        //redimensionar
        auto add    = (floor(m_maxSize/2)-1);
        m_maxSize   = m_maxSize + add;
        T *new_list = new T[m_maxSize];
        m_list      = update_list(add-1, new_list);
        m_begin     = add-1;
    }
    if(isEmpty()) m_list[m_begin] = data;
    else{
        m_list[m_begin-1] = data;
        --m_begin;
    }
    ++m_length;
}

template <class T>
void List_Array<T>::insert_Back(T data){
    if(isBackFull()){
        //redimensionar
        m_maxSize   = m_maxSize + (floor(m_maxSize/2)-1);
        T *new_list = new T[m_maxSize];
        m_list      = update_list(0, new_list);
    }
    if(isEmpty()) m_list[m_begin]          = data;
    else          m_list[m_begin+m_length] = data;
    ++m_length;
    
}

template <class T>
void List_Array<T>::insert_Position(unsigned long pos, T data){
    if( pos <= m_length-1 ){
        if(isBackFull()){
            m_maxSize   = m_maxSize + (floor(m_maxSize/2)-1);
            T *new_list = new T[m_maxSize];
            m_list      = update_list(0, new_list);
        }
        if(isEmpty()) m_list[m_begin] = data;
        else{
            auto size = m_begin + m_length;
            for(unsigned long i = size+1; i>m_begin+pos; --i)
                m_list[i] = m_list[i-1];
            m_list[m_begin+pos] = data;
        }
        ++m_length;
    }
}

template <class T>
void List_Array<T>::replace_Position(unsigned long pos, T data){
    m_list[m_begin+pos] = data;
}

template <class T>
T List_Array<T>::retrieve_Position(unsigned long pos){
    return m_list[m_begin+pos];
}

template <class T>
void List_Array<T>::delete_Front(){
    ++m_begin;
    --m_length;
}

template <class T>
void List_Array<T>::delete_Back(){
    --m_length;
}

template <class T>
void List_Array<T>::delete_Position(unsigned long pos){
    auto begin = m_begin + pos;
    auto size  = m_begin + m_length;
    for (auto i = begin; i<size; ++i)
        m_list[i] = m_list[i+1];
    --m_length;
}


template <class T>
T* List_Array<T>::update_list(unsigned long begin, T *&new_list){
    auto size = begin+m_begin+m_length;
    for(unsigned long i = begin; i<size; ++i)
        new_list[i] = m_list[i-begin];
    return new_list;
}

#endif /* list_array_h */

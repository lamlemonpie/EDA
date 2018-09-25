//
//  hashNode.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef hashNode_h
#define hashNode_h

#include<iostream>

template <typename T, typename U>
class HashNode {
public:
    T m_key;
    U m_value;
    HashNode * m_pNext;
public:
    HashNode(T &key, U &value){
        this->m_key   = key;
        this->m_value = value;
        m_pNext       = NULL;
    }
    T    getKey();
    U    getValue();
    void setKey(const T &key);
    void setValue(const U &alue);
};


#endif /* hashNode_h */

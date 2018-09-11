//
//  node.h
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef node_h
#define node_h

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T m_data;
    Node * m_pNext;
    Node(T data){
        m_data = data;
        m_pNext = NULL;
    }
};

#endif /* node_h */

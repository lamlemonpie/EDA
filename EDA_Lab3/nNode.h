//
//  nNode.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/10/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef nNode_h
#define nNode_h
#include <vector>
#include <iostream>

using namespace std;

template<size_t N, class T>
class nTree;


template <size_t N, class T>
class nNode {
    T                          m_data;
    std::vector<nNode<N,T>* >* m_pChildren;
    nNode<N,T>*                m_pParent;
    
    
public:
    nNode(T value){
        this->m_data      = value;
        this->m_pChildren = new std::vector<nNode<N,T>*>;
        this->m_pParent   = NULL;
    }
    
    nNode(T value, nNode<N,T>* parent){
        this->m_data      = value;
        this->m_pChildren = new std::vector<nNode<N,T>*>;
        this->m_pParent   = parent;
    }
    
    bool isChildrenFull(){
        //cout << m_pChildren->size() << " -- " << N << endl;
        if (m_pChildren->size() == N) return true;
        return false;
    }
    
    T   getData(){
        return m_data;
    }
    
    
    friend class nTree<N,T>;
};


#endif /* nNode_h */

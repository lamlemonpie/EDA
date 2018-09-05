//
//  binary_tree.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/4/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include "node_binary_tree.h"

template<class T>
class Binary_Tree {
    Node_BinaryTree<T> * m_pRoot;
    
public:
    Binary_Tree();
    
    bool Add(T data);
};


template<class T>
Binary_Tree<T>::Binary_Tree(){
    m_pRoot = NULL;
}

template<class T>
bool Binary_Tree<T>::Add(T data){
    if(!m_pRoot) m_pRoot = new Node_BinaryTree<T>(data);
    else{
        Node_BinaryTree<T> *p,*q;
        p = q = m_pRoot;
        while(q!=NULL){
            p=q;
            if(q->m_data==data) return false;
            if(q->m_data<data)  q=q->m_pRight;
            else             q=q->m_pLeft;
        }
        if(p->m_data<data) p->m_pRight = new Node_BinaryTree<T>(data);
        else               p->m_pLeft  = new Node_BinaryTree<T>(data);
    }
    return true;
}

#endif /* binary_tree_h */

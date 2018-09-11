//
//  nTree.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/10/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef nTree_h
#define nTree_h
#include <iostream>
#include "nNode.h"

template <size_t N, class T>
class nTree {
    nNode<N,T>* m_pRoot;
public:
    nTree(){
        m_pRoot = NULL;
    }
    nNode<N,T>* getRoot(){
        return m_pRoot;
    }
    nNode<N,T>* find(T node, nNode<N,T>* nodeIt){
        if(!nodeIt) return NULL;
        if(nodeIt->getData() == node) return nodeIt;
        else{
            for(auto &i: *(nodeIt->m_pChildren)){
                nNode<N,T> *found = find(node,i);
                if(found) return found;
            }
        }
        return NULL;
    }
    bool add(T value, T node){
        if(!m_pRoot){
            m_pRoot = new nNode<N,T>(value);
            return true;
        }
        else{
            nNode<N,T> * nodeToInsert = find(node,m_pRoot);
            if( nodeToInsert && !nodeToInsert->isChildrenFull() ){
                nodeToInsert->m_pChildren->push_back( new nNode<N,T>(value,nodeToInsert) );
                return true;
            }
        }
        return false;
    }
    void postOrder(nNode<N, T>* node){
        if (!node) return;
        for(auto &i: *(node->m_pChildren))
            postOrder(i);
        cout << node->m_data << "-";
        if (node->m_pChildren->empty()) return;
    }
    void preOrder(nNode<N,T>*node){
        if (!node) return;
        cout << node->m_data << "-";
        for(auto &i: *(node->m_pChildren))
            preOrder(i);
        if (node->m_pChildren->empty()) return;
    }
    void inOrder(nNode<N,T>*node){
        if (!node) return;
        if (node->m_pChildren->empty()) {
            cout<<node->m_data<<"-";
            return;
        };
        inOrder(node->m_pChildren->at(0));
        cout << node->m_data << "-";
        for(size_t i=1; i<node->m_pChildren->size(); ++i)
            inOrder(node->m_pChildren->at(i));
    }
    
};


#endif /* nTree_h */

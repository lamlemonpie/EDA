//
//  playground.h
//  EDA
//
//  Created by Alejandro Larraondo on 10/9/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef playground_h
#define playground_h

#include "bTree.h"
#include <unordered_set>

template<class T>
void invertTree(bNode<T> * node){
    if(!node) return;
    bNode<T> * tmp;
    tmp            = node->m_pLeft;
    node->m_pLeft  = node->m_pRight;
    node->m_pRight = tmp;
    
    invertTree(node->m_pLeft);
    invertTree(node->m_pRight);
}

//Sin pila ni recursividad, postfija un arbol.
template<class T>
void postFija(bTree<T> tree){
    unordered_set<bNode<T>*> visitados;
    bNode<T> * temp = tree.root();
    //Mientras que haya un nodo y este no haya sido visitado
    while(temp && visitados.find(temp) == visitados.end()){
        
        //izquierda (Si existe y no ha sido visitado)
        if(temp->m_pLeft && visitados.find(temp->m_pLeft) == visitados.end())
            temp = temp->m_pLeft;
        //derecha (Si existe y no ha sido visitado)
        else if(temp->m_pRight && visitados.find(temp->m_pRight) == visitados.end())
            temp = temp->m_pRight;
        //imprimir (No tiene hijos y no ha sido visitado)
        else{
            cout << " " << temp->m_data;
            visitados.insert(temp);
            temp = tree.root();
            }
    }
}


#endif /* playground_h */

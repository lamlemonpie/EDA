//
//  bTree.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/4/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef bTree_h
#define bTree_h

#include "bNode.h"
#include <fstream>
#include <stdio.h>

using namespace std;

template<class T>
class bTree {
    bNode<T> * m_pRoot;
public:
    bTree();
    bool Add(T data);
    void generateDot(string &dot, bNode<T> * node);
    void getDot();
    void showDot();
};
template<class T>
bTree<T>::bTree(){
    m_pRoot = NULL;
}
template<class T>
bool bTree<T>::Add(T data){
    if(!m_pRoot) m_pRoot = new bNode<T>(data);
    else{
        bNode<T> *p,*q;
        p = q = m_pRoot;
        while(q!=NULL){
            p=q;
            if(q->m_data==data) return false;
            if(q->m_data<data)  q=q->m_pRight;
            else                q=q->m_pLeft;
        }
        if(p->m_data<data) p->m_pRight = new bNode<T>(data);
        else               p->m_pLeft  = new bNode<T>(data);
    }
    return true;
}

template<class T>
void bTree<T>::generateDot(string& dot, bNode<T>* node){
    if (!node) return;
    if (node->m_pLeft)
        dot = dot + to_string(node->m_data) + " -> " + to_string(node->m_pLeft->m_data) + "; \n";
    if (node->m_pRight)
        dot = dot + to_string(node->m_data) + " -> " + to_string(node->m_pRight->m_data) + "; \n";
    generateDot(dot,  node->m_pLeft);
    generateDot(dot,  node->m_pRight);
}

template<class T>
void bTree<T>::getDot(){
    string dot = "digraph G {\n";
    generateDot(dot,m_pRoot);
    dot = dot + "}";
    cout << dot<<endl;
    //Generar archivo dot.
    ofstream dotFile;
    dotFile.open("tree.dot");
    dotFile << dot;
    dotFile.close();
}

template<class T>
void bTree<T>::showDot(){
    system("atom tree.dot");
    system("dot -Tpng tree.dot -o tree.png");
    system("open tree.png");
}

#endif /* bTree_h */

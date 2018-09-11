//
//  postToTree.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/10/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef postToTree_h
#define postToTree_h

#include <iostream>
#include <list>
#include "bNode.h"

using namespace std;

class PostOrder {
    list<bNode<string> *> m_stack;
public:
    PostOrder( list<string> postOrder ){
        while(!postOrder.empty()){
            //Caso digito
            if(isdigit(postOrder.front()[0])){
                m_stack.push_back(new bNode<string>( postOrder.front() ));
                postOrder.pop_front(); //Eliminamos el caracter del string
            }
            //Caso operador
            else{
                bNode<string> * oper = new bNode<string>(postOrder.front());
                oper->m_pLeft  = m_stack.back();  m_stack.pop_back();
                oper->m_pRight = m_stack.back(); m_stack.pop_back();
                m_stack.push_back(oper);
                postOrder.pop_front(); //Eliminamos el caracter del string
            }
        }
        showTree(m_stack.front(), 0);
    }
    void showTree(bNode<string>* tree, int i){
        if(!tree) return;
        i += 3;
        showTree(tree->m_pRight,i);
        for(int j = 0; j < i; j++)
            cout<<" ";
        cout << tree->m_data;
        cout<<endl;
        showTree(tree->m_pLeft,i);
    }
};

#endif /* postToTree_h */

//
//  node_binary_tree.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/4/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef node_binary_tree_h
#define node_binary_tree_h


template<class T>
class Node_BinaryTree
{
public:
    T m_data;
    Node_BinaryTree<T> *m_pRight;
    Node_BinaryTree<T> *m_pLeft;
public:
    Node_BinaryTree(T data)
    {
        m_data=data;
        m_pRight=m_pLeft=NULL;
    }
};

#endif /* node_binary_tree_h */

//
//  bNode.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/4/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef bNode_h
#define bNode_h


template<class T>
class bNode
{
public:
    T m_data;
    bNode<T> *m_pRight;
    bNode<T> *m_pLeft;
public:
    bNode(T data)
    {
        m_data=data;
        m_pRight=m_pLeft=NULL;
    }
    friend class PostOrder;
};

#endif /* bNode_h */

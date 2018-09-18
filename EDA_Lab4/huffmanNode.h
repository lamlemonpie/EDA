//
//  huffmanNode.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/17/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef huffmanNode_h
#define huffmanNode_h

#include <iostream>

class HuffmanNode {
    size_t m_frequency;
    char   m_value;
    string path;
    bool   isLeaf;
    bool   isRight;
    int    m_id;
    HuffmanNode* m_pFather;
    HuffmanNode* m_pLeft;
    HuffmanNode* m_pRight;
public:
    HuffmanNode(char value,size_t frequency){
        this->m_frequency   = frequency;
        this->m_value       = value;
        m_pFather = m_pLeft = m_pRight = NULL;
        this->isLeaf        = true;
    }
    HuffmanNode(size_t frequency){
        this->m_frequency = frequency;
        m_pFather = m_pLeft = m_pRight = NULL;
        this->isLeaf      = false;
    }
    size_t const getFrequency(){
        return m_frequency;
    }
    string getValFreq(){
        string valFreq;
        if(isLeaf)
            valFreq = "{"+string(&m_value)+"-"+to_string(m_frequency)+"}";
        else
            valFreq = "{"+to_string(m_frequency)+"}";
        return valFreq;
    }
    friend class HuffmanCoding;
};

bool compareHuffmanNode(HuffmanNode* a, HuffmanNode* b){
    return (a->getFrequency() < b->getFrequency());
}

#endif /* huffmanNode_h */

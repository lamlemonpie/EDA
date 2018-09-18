//
//  test_Lab4.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/11/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Lab4_h
#define test_Lab4_h

#include "huffmanCoding.h"

void test_frecuency(string paragraph,string encrypt,string save,string save2)
{
    HuffmanCoding HC(paragraph);
    HC.printFrequency();
    HC.printPaths();
    HC.getDot();
    HC.encrypt(encrypt, save);
    HC.decrypt(save,save2);
}

#endif /* test_Lab4_h */

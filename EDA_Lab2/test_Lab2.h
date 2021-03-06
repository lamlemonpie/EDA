//
//  test_Lab2.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/3/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Lab2_h
#define test_Lab2_h

#include <iostream>
#include "radix_sort.h"


void test_Radix(vector<int> &a){
    radix(a);
}

void test_RadixList(List_Pointer<int> &a){
    radix_linkedList(a);
}

#endif /* test_Lab2_h */

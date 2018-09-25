//
//  test_Lab5.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Lab5_h
#define test_Lab5_h

#include "dictionary.h"
#include <iostream>

void test_dictionary(string dict, string file){
    Dictionary dic(dict);
    dic.check(file);
}


#endif /* test_Lab5_h */

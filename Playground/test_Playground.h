//
//  test_Playground.h
//  EDA
//
//  Created by Alejandro Larraondo on 10/9/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Playground_h
#define test_Playground_h

#include <iostream>
#include <vector>
#include "bTree.h"
#include "playground.h"

using namespace std;

void test_playground(){
    //Invierte arbol binario.
    bTree<int> tree;
    vector<int> v = {15,6,7,8,15,4,1,5,50,17,47,49,38};
    for(auto i:v)
        tree.Add(i);
    invertTree(tree.root());
    //tree.getDot();
    postFija(tree);
    cout << endl;
}

#endif /* test_Playground_h */

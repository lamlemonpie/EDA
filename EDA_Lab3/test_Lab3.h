//
//  test_Lab3.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/4/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Lab3_h
#define test_Lab3_h

#include <iostream>
#include "bTree.h"
#include "nTree.h"
#include "postToTree.h"

using namespace std;


void test_BTree(){
    bTree<int> tree;
    
    vector<int> v = {15,6,7,8,15,4,1,5,50,17,47,49,38};
    for(auto i:v)
        tree.Add(i);
    tree.getDot();
    tree.showDot();
}

void testNTree(){
    nTree<3,int> NTree;
    NTree.add(3,0);
    NTree.add(1,3);
    NTree.add(2,3);
    NTree.add(4,3);
    
    NTree.add(8,1);
    NTree.add(0,1);
    
    NTree.add(5,2);
    NTree.add(6,2);
    NTree.add(7,2);
    
    NTree.postOrder(NTree.getRoot());
    cout << endl;
    NTree.preOrder(NTree.getRoot());
    cout << endl;
    NTree.inOrder(NTree.getRoot());
    cout << endl;
}

void testPostToTree(){
    
    list<string> post = {"1","2","+","4","*"};
    PostOrder semTree(post);
}

#endif /* test_Lab3_h */

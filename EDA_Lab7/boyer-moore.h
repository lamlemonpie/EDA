//
//  boyer-moore.h
//  EDA
//
//  Created by Alejandro Larraondo on 10/30/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef boyer_moore_h
#define boyer_moore_h

#include <iostream>
#include <algorithm>

using namespace std;

vector<int> lastOccurenceFunction(string P){
    vector<int> L(256,-1);
    for(int i=0; i<P.size();++i)
        L[(int)P[i]] = i;
    return L;
}

int BoyerMooreMatch(string T, string P){
    vector<int> L = lastOccurenceFunction(P);
    int m = (int)P.size(), n = (int)T.size();
    int i = (int)m-1, j = (int)m-1, l;
    do{
        if(T[i] == P[j]){
            if(j==0) return i;
            else{
                --i;
                --j;
            }
        }
        else{
            l = L[(int)T[i]];
            i = i+m-min(j,1+l);
            j = m-1;
        }
    }
    while(i < n);
    return -1;
}



#endif /* boyer_moore_h */

//
//  kmp.h
//  EDA
//
//  Created by Alejandro Larraondo on 10/30/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef kmp_h
#define kmp_h

#include <iostream>
#include <map>

vector<int> failureFunction(string P){
    vector<int> F(P.size());
    F[0] = 0;
    int i = 1, j = 0;
    size_t m = P.size();
    while(i<m){
        if( P[i] == P[j] ){
            F[i] = j+1;
            ++i;
            ++j;
        }
        else{
            if(j>0) j = F[j-1];
            else{
                F[i]=0;
                ++i;
            }
        }
    }
    return F;
}

int KMPMatch(string T, string P){
    vector<int> F = failureFunction(P);
    int    i = 0, j = 0;
    size_t n = T.size(), m = P.size();
    while(i<n){
        if(T[i] == P[j]){
            if( j == m-1)   return i-j;
            else{
                ++i;
                ++j;
            }
        }
        else{
            if(j>0) j = F[j-1];
            else    ++i;
        }
    }
    return -1;
}

#endif /* kmp_h */

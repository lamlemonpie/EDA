//
//  bruteForce.h
//  EDA
//
//  Created by Alejandro Larraondo on 10/23/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef bruteForce_h
#define bruteForce_h

#include <iostream>

int bruteForce(string T, string P){
    size_t tsize = T.size();
    size_t psize = P.size();
    for(int i=0; i<=(tsize-psize);++i){
        int j=0;
        while( j<psize && T[i+j]==P[j] )
            j=j+1;
        if(j==psize)    return i;
    }
    return -1;
}



#endif /* bruteForce_h */

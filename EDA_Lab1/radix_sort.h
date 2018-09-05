//
//  radix_sort.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/3/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef radix_sort_h
#define radix_sort_h

#include <iostream>
#include <cmath>
#include <vector>

#include "list_pointer.h"

using namespace std;

typedef vector<int> vect;
typedef vector<vect> vec_radix;

typedef List_Pointer<int> list;
typedef List_Pointer<list> list_radix;

list radix_linkedList( list &a ){
    list_radix bucket(10);
    int temp, m=0, n=(int)a.size();
    for(size_t i = 0; i<5; i++){
        for(size_t j=0;j<n;j++){
            temp= (int)(a[j]/pow(10,i))%10;
            bucket[temp].insert_Back(a[j]);
        }
        //Copiamos del vector radix al vector
        //original para volver a realizar el proc.
        for(size_t k=0;k<10;k++){
            for(size_t l=0;l<bucket[k].size();l++){
                a[m]=bucket[k][l];
                m++;
            }
            //Vaciamos vec para volver a llenarlo
            //en la siguiente vuelta.
            bucket[k].clear();
        }
        m=0;
        a.print();
    }
    return a;
}


void print_radix(const vect &v ){
    for (auto i:v)
        cout << i << " ";
    cout << endl;
}

vect radix(vect &a){
    vec_radix vec(10);
    int temp , m=0, n=(int)a.size();
    for(int i=0;i<7;i++){
        for(int j=0;j<n;j++){
            temp= (int)(a[j]/pow(10,i))%10;
            vec[temp].push_back(a[j]);
        }
        //Copiamos del vector radix al vector
        //original para volver a realizar el proc.
        for(int k=0;k<10;k++){
            for(int l=0;l<vec[k].size();l++){
                a[m]=vec[k][l];
                m++;
            }
            //Vaciamos vec para volver a llenarlo
            //en la siguiente vuelta.
            vec[k].clear();
        }
        m=0;
        print_radix(a);
    }
    return a;
}



#endif /* radix_sort_h */

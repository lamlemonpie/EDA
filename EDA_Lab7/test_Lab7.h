//
//  test_Lab7.h
//  EDA
//
//  Created by Alejandro Larraondo on 10/23/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Lab7_h
#define test_Lab7_h

#include "bruteForce.h"
#include "boyer-moore.h"
#include "kmp.h"

void test_bruteForce(string T, string P){
    cout << "BRUTE FORCE" << endl;
    cout << "Buscando: " << P << "\nen: " << T << endl;
    cout << "La posición de inicio es: " << bruteForce(T , P) << endl;
    cout << endl;
}

void test_boyermoore(string T, string P){
    cout << "BOYER-MOORE" << endl;
    cout << "Buscando: " << P << "\nen: " << T << endl;
    cout << "La posición de inicio es: " << BoyerMooreMatch(T , P) << endl;
    cout << endl;
}

void test_kmp(string T, string P){
    cout << "KMP" << endl;
    cout << "Buscando: " << P << "\nen: " << T << endl;
    cout << "La posición de inicio es: " << KMPMatch(T , P) << endl;
    cout << endl;
}

#endif /* test_Lab7_h */

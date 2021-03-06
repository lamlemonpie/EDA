//
//  main.cpp
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#include <iostream>

#include "Playground/test_Playground.h"

#include "EDA_Lab1/test_Lab1.h"
#include "EDA_Lab2/test_Lab2.h"
#include "EDA_Lab3/test_Lab3.h"
#include "EDA_Lab4/test_Lab4.h"
#include "EDA_Lab5/test_Lab5.h"
#include "EDA_Lab7/test_Lab7.h"


using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "ESTRUCTURAS DE DATOS" << endl;
    
    //Playground
    //test_playground();
    
    //EDA_Lab1
    //test_Lista_Puntero();
    //test_Cola_Puntero();
    //test_Pila_Puntero();

    //test_Lista_Array();
    //test_Cola_Array();
    //test_Pila_Array();
    
    //EDA_Lab2
    //vect a = {82,31,53,18,27,46,17,38,47,212};
    //vect b = {82,31,53,18,27,46,17,38,10,212};
    //vect c = {69,98,77,26,95,124,83,52,31,50,10};
    //vect d = {43,21,5,42,11,27};
    //vect e = {30,30,21,21,41,24,32,14,12,53};
    //test_Radix(a);
    
    //List_Pointer<int> lista;
    //lista.insert_Back(43);
    //lista.insert_Back(21);
    //lista.insert_Back(5);
    //lista.insert_Back(42);
    //lista.insert_Back(11);
    //lista.insert_Back(27);
    //test_RadixList(lista);
    
    //EDA_Lab3
    //test_BTree();
    //testNTree();
    //testPostToTree();
    
    
    //EDA_Lab4
    //test_frecuency("EDA_Lab4/mobydick.txt");
    //test_frecuency("EDA_Lab4/test.txt");
    //test_frecuency("EDA_Lab4/test.txt","EDA_Lab4/test.txt","EDA_Lab4/encrypted.txt","EDA_Lab4/decrypted.txt");
    
    //EDA_Lab5
    //test_dictionary("EDA_Lab5/spanishDictionary.txt","EDA_Lab5/test.txt");
    
    
    //EDA_Lab7
    test_bruteForce("maravillado", "villa");
    test_boyermoore("maravillado", "villa");
    test_kmp("maravillado", "villa");
    
    return 0;
}

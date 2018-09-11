//
//  test_Lab1.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/3/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef test_Lab1_h
#define test_Lab1_h

#include "list_pointer.h"
#include "stack_pointer.h"
#include "queue_pointer.h"
#include "list_array.h"
#include "stack_array.h"
#include "queue_array.h"


void test_Lista_Puntero(){
    cout << "LISTA PUNTERO" << endl;
    List_Pointer<float> lista_puntero;
    cout << "Insertar delante 3: "<< endl;
    lista_puntero.insert_Front(3);
    cout << "Lista: ";lista_puntero.print();
    cout << "Insertar atrás 4: "<< endl;
    lista_puntero.insert_Back(4);
    cout << "Lista: ";lista_puntero.print();
    cout << "Insertar delante 2: "<< endl;
    lista_puntero.insert_Front(2);
    cout << "Lista: ";lista_puntero.print();
    cout << "¿Está el 4?: " << lista_puntero.find(4) << endl;
    cout << "Insertar posición 0 el 1.3" << endl;
    lista_puntero.insert_Position(0, 1.3);
    cout << "Lista: ";lista_puntero.print();
    cout << "Insertar posición 2 el 2.4" << endl;
    lista_puntero.insert_Position(2, 2.4);
    cout << "Lista: ";lista_puntero.print();
    cout << "Reemplazar posición 1 con 1.89" << endl;
    lista_puntero.replace_Position(1, 1.89);
    cout << "Lista: ";lista_puntero.print();
    cout << "Eliminar atrás" << endl;
    lista_puntero.delete_Back();
    cout << "Lista: ";lista_puntero.print();
    cout << "Eliminar delante" << endl;
    lista_puntero.delete_Front();
    cout << "Lista: ";lista_puntero.print();
    cout << "Pos 1: " << lista_puntero.retrieve_Position(1) << endl;
    cout << "Eliminar posición 1" << endl;
    lista_puntero.delete_Position(1);
    cout << "Lista: ";lista_puntero.print();
    cout << "Eliminar posición 0" << endl;
    lista_puntero.delete_Position(0);
    cout << "Lista: ";lista_puntero.print();
    cout << "Eliminar posición 0" << endl;
    lista_puntero.delete_Position(0);
    cout << "Lista: ";lista_puntero.print();
    cout << "Pos 3: " << lista_puntero.retrieve_Position(3) << endl;
}

void test_Cola_Puntero(){
    cout << "COLA PUNTERO" << endl;
    Queue_Pointer<float> cola_puntero;
    cout << "PUSH 12" << endl;
    cola_puntero.push(12);
    cout << "Cola: ";cola_puntero.print();
    cout << "PUSH 15" << endl;
    cola_puntero.push(15);
    cout << "Cola: ";cola_puntero.print();
    cout << "PUSH 5" << endl;
    cola_puntero.push(5);
    cout << "Cola: ";cola_puntero.print();
    cout << "Pop: " <<cola_puntero.pop() << endl;
    cout << "Cola: ";cola_puntero.print();
    cout << "Pop: " <<cola_puntero.pop() << endl;
    cout << "Cola: ";cola_puntero.print();
    cout << "Pop: " <<cola_puntero.pop() << endl;
    cout << "Cola: ";cola_puntero.print();
}

void test_Pila_Puntero(){
    cout << "PILA PUNTERO" << endl;
    Stack_Pointer<float> pila_puntero;
    cout << "PUSH 5" << endl;
    pila_puntero.push(5);
    cout << "Pila: ";pila_puntero.print();
    cout << "PUSH 10" << endl;
    pila_puntero.push(10);
    cout << "Pila: ";pila_puntero.print();
    cout << "PUSH 15" << endl;
    pila_puntero.push(15);
    cout << "Pila: ";pila_puntero.print();
    cout << "Pop: " << pila_puntero.pop() << endl;
    cout << "Pila: ";pila_puntero.print();
    cout << "Pop: " << pila_puntero.pop() << endl;
    cout << "Pila: ";pila_puntero.print();
}

void test_Lista_Array(){
    List_Array<float> lista_array;
    cout << "Insertar delante 2: "<< endl;
    lista_array.insert_Front(2);
    cout << "Lista: ";lista_array.print();
    cout << "Insertar atrás 3: "<< endl;
    lista_array.insert_Back(3);
    cout << "Lista: ";lista_array.print();
    cout << "Insertar delante 1: "<< endl;
    lista_array.insert_Front(1);
    cout << "Lista: ";lista_array.print();
    cout << "Está 3?: " << lista_array.find(3) << endl;
    cout << "Eliminar posición 1: " << endl;
    lista_array.delete_Position(1);
    cout << "Lista: ";lista_array.print();
    cout << "Insertar posición 1 el 1.5: "<< endl;
    lista_array.insert_Position(1, 1.5);
    cout << "Lista: ";lista_array.print();
    cout << "Reemplazar posición 2 con 4" << endl;
    lista_array.replace_Position(2, 4);
    cout << "Lista: ";lista_array.print();
}

void test_Cola_Array(){
    cout << "COLA ARRAY" << endl;
    Queue_Array<float> cola_array;
    for(int i=0; i<7; i++){
        cola_array.push(i);
        cout <<"PUSH "<< i <<":"<< endl;
        cola_array.print();
    }
    for(int j=6; j>-1; j--){
        cola_array.pop();
        cout << "POP" << endl;
        cola_array.print();
    }
}

void test_Pila_Array(){
    cout << "PILA ARRAY" << endl;
    Stack_Array<float> pila_array;
    for(int i=0; i<7; i++){
        cout << "PUSH "<< i << endl;
        pila_array.push(i);
        cout << "Pila: ";pila_array.print();
    }
    for(int j=6; j>-1; j--){
        cout << "Pop: " << pila_array.pop() << endl;
        cout << "Pila: ";pila_array.print();
    }
}



#endif /* test_Lab1_h */

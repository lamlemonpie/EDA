//
//  main.cpp
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#include <iostream>

#include "list_pointer.h"
#include "stack_pointer.h"
#include "queue_pointer.h"


using namespace std;


void test_Lista_Puntero(){
    cout << "LISTA PUNTERO" << endl;
    List_Pointer<float> lista_puntero;
    lista_puntero.insert_Front(3);
    lista_puntero.print();
    lista_puntero.insert_Back(4);
    lista_puntero.print();
    lista_puntero.insert_Front(2);
    lista_puntero.print();
    lista_puntero.insert_Position(0, 1.3);
    lista_puntero.print();
    lista_puntero.insert_Position(2, 2.4);
    lista_puntero.print();
    lista_puntero.replace_Position(1, 1.89);
    lista_puntero.print();
    lista_puntero.delete_Back();
    lista_puntero.print();
    lista_puntero.delete_Front();
    lista_puntero.print();
    cout << "Pos 1: " << lista_puntero.retrieve_Position(1) << endl;
    lista_puntero.delete_Position(1);
    lista_puntero.print();
    lista_puntero.delete_Position(0);
    lista_puntero.print();
    lista_puntero.delete_Position(0);
    lista_puntero.print();
    cout << "Pos 12: " << lista_puntero.retrieve_Position(3) << endl;
    cout << "¿Está?: " << lista_puntero.find(4) << endl;
}

void test_Cola_Puntero(){
    cout << "COLA PUNTERO" << endl;
    Queue_Pointer<float> cola_puntero;
    cola_puntero.push(12);
    cola_puntero.print();
    cola_puntero.push(15);
    cola_puntero.print();
    cola_puntero.push(5);
    cola_puntero.print();
    cout << "Pop: " <<cola_puntero.pop() << endl;
    cola_puntero.print();
    cout << "Front: " <<cola_puntero.front() << endl;
    cola_puntero.print();
    cout << "Pop: " <<cola_puntero.pop() << endl;
    cola_puntero.print();
    cout << "Pop: " <<cola_puntero.pop() << endl;
    cola_puntero.print();
}

void test_Pila_Puntero(){
    cout << "PILA PUNTERO" << endl;
    Stack_Pointer<float> pila_puntero;
    pila_puntero.push(5);
    pila_puntero.print();
    pila_puntero.push(10);
    pila_puntero.print();
    pila_puntero.push(15);
    pila_puntero.print();
    cout << "Pop: " << pila_puntero.pop() << endl;
    pila_puntero.print();
    cout << "Top: " << pila_puntero.top() << endl;
    pila_puntero.print();
}

int main(int argc, const char * argv[]) {
    
    cout << "ESTRUCTURAS DE DATOS" << endl;
    
    //test_Lista_Puntero();
    //test_Cola_Puntero();
    //test_Pila_Puntero();
    
    return 0;
}

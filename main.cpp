//
//  main.cpp
//  EDA_Tarea1
//
//  Created by Alejandro Larraondo on 8/18/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#include <iostream>

#include "list_pointer.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Estructuras de Datos" << endl;
    
    List_Pointer<int> lista_puntero;
    lista_puntero.insert_Front(3);
    lista_puntero.insert_Back(4);
    lista_puntero.insert_Front(2);
    lista_puntero.print();
    cout << "¿Está?: " << lista_puntero.find(4) << endl;
    return 0;
}

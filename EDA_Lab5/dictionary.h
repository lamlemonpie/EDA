//
//  dictionary.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/25/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef dictionary_h
#define dictionary_h

#include <stdio.h>
#include "hashTable.h"

class Dictionary {
    HashTable<int,string> * m_pHash;
public:
    //Al iniciar un diccionario le damos un archivo para que
    //cargue estas palabras al hash.
    Dictionary(string text){
        m_pHash = new HashTable<int,string>;
        cout << "Cargando diccionario..."<< endl;
        string frase;
        fstream file;
        file.open(text);
        string line;
        while (!file.eof()){
            getline(file,line);
            m_pHash->insert(stringToInt(line),line);
        }
        file.close();
        cout << "Diccionario cargado!" << endl;
    };
    //Funcion para convertir una palabra en una llave.
    int stringToInt(string text){
        int val = 0;
        for(int i=0;i<text.size();i++){
            unsigned char character = text[i];
            val+= (int)(character);
        }
        return val;
    }
    //Revisamos un texto e imprimimos si las palabras
    //Son correctas o no.
    void check(string text){
        ifstream file; file.open (text);
        if (!file.is_open()) return;
        string word;
        while (file >> word){
            int key = stringToInt(word);
            if(m_pHash->search(key,word)) printf(" %10s <- Bien\n", word.c_str());
            else                          printf(" %10s <- Mal\n", word.c_str());
        }
        file.close();
    }
};


#endif /* dictionary_h */

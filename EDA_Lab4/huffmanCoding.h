//
//  huffmanCoding.h
//  EDA
//
//  Created by Alejandro Larraondo on 9/11/18.
//  Copyright © 2018 Alejandro Larraondo. All rights reserved.
//

#ifndef huffmanCoding_h
#define huffmanCoding_h

#include <iostream>
#include <fstream>
#include <map>
#include "huffmanNode.h"

using namespace std;

class HuffmanCoding {
    map<char,size_t>    m_frequency;     //Almacenar frecuencias
    map<char,string>    m_paths;         //Almacenar caminos
    list<HuffmanNode *> m_treeGenerator; //Realizar arbolHuffman
    list<HuffmanNode *> m_leafs;         //Acceso a las ojas del huffman
    string              file;            //Archivo utilizado para árbol
    HuffmanNode *       m_pTreeRoot;     //Apuntador a la cabeza del árbolHuffman
private:
    void   frequencyToTreeGenerator();
    void   treeGeneratorSort();
    void   makeTree();
    void   findPaths();
    void   generateDot(string& dot, HuffmanNode* node);
    void   setIDs(HuffmanNode* node, int& i,string& dot);
    void   showDot();
public:
    HuffmanCoding(string paragraphFile);
    void   getDot();
    void   printFrequency();
    void   printPaths();
    void   encrypt(string textToEncrypt,string textToSave);
    void   decrypt(string textToDecrypt,string textToSave);
};

HuffmanCoding::HuffmanCoding(string paragraphFile){
    //Abrimos el archivo y llenamos un mapa de frecuencias.
    //Mapa<llave,valor> llave = letra, valor = frecuencia.
    ifstream para(paragraphFile);
    char read;
    while(para >> std::noskipws >> read){
        if(m_frequency.find(read) == m_frequency.end()) m_frequency[read]=1;
        else                                            m_frequency[read]++;
    }
    para.close();
    file        = paragraphFile;
    m_pTreeRoot = NULL;
    makeTree(); //Árbol de Huffman.
    findPaths(); //Encontrar caminos.
}

//Funcion para imprimir frecuencias.
void HuffmanCoding::printFrequency(){
    for (auto i:m_frequency)
        cout << i.first << "->" <<  i.second << endl;
}

//Funcion para imprimir caminos.
void HuffmanCoding::printPaths(){
    for (auto i:m_paths)
        cout << i.first << "->" <<  i.second << endl;
}

//Funcion para ordenar la lista treeGenerator
//utilizado en makeTree Huffman.
void HuffmanCoding::treeGeneratorSort(){
    m_treeGenerator.sort(compareHuffmanNode);
}

//Guardamos los datos de frecuencia en una lista
//de apuntadores a nodos Huffman y también en la lista
//leafs para tener acceso a estos nodos.
void HuffmanCoding::frequencyToTreeGenerator(){
    for(auto& freq: m_frequency){
        HuffmanNode * node = new HuffmanNode(freq.first,freq.second);
        m_treeGenerator.push_back(node); //Para generar el arbol.
        m_leafs.push_back(node); //Para generar el camino.
    }
}

//Realiza arbol Huffman: En la lista ordenada de nodos, se obtienen
//(y quitan de la lista) los dos primeros elementos (A,B) y se suman
//entre ellos. Esta suma genera un nuevo nodo (TMP).
//Este nuevo nodo apuntará a A y B. Estos apuntan a TMP y se guarda TMP
//en la lista para volver a ser ordenada.
//Guadaremos cuál es el derecho para generar el camino de abajo hacia arriba.
void HuffmanCoding::makeTree(){
    frequencyToTreeGenerator();
    while(m_treeGenerator.size() > 1){
        treeGeneratorSort();
        HuffmanNode * a   = m_treeGenerator.front(); m_treeGenerator.pop_front();
        HuffmanNode * b   = m_treeGenerator.front(); m_treeGenerator.pop_front();
        HuffmanNode * tmp = new HuffmanNode( a->getFrequency() + b->getFrequency() );
        tmp->m_pLeft      = a;
        a->m_pFather      = tmp;
        a->isRight        = false;
        tmp->m_pRight     = b;
        b->m_pFather      = tmp;
        b->isRight        = true;
        m_treeGenerator.push_back(tmp);
    }
    m_pTreeRoot = m_treeGenerator.front(); m_treeGenerator.pop_front();
}

//Funcion para generar los caminos de cada letra
//Se recorre de abajo hacia arriba del arbol, verificando
//si el nodo es derecho o izquierdo.
void HuffmanCoding::findPaths(){
    for(auto &i: m_leafs){
        HuffmanNode * tmp = i;
        string path = "";
        while(tmp != m_pTreeRoot){
            if(tmp->isRight) path = string("1")+path;
            else             path = string("0")+path;
            tmp=tmp->m_pFather;
        }
        m_paths[i->m_value]=path;
    }
}

//Funcion para codificar un texto
void HuffmanCoding::encrypt(string textToEncrypt,string textToSave){
    ifstream text(textToEncrypt);
    string encrypted;
    ofstream save(textToSave);
    char read;
    while(text >> std::noskipws >> read){
        encrypted+= m_paths[read];
    }
    save << encrypted; text.close(); save.close();
}

//Funcion para decodificar un texto codificado
void HuffmanCoding::decrypt(string textToDecrypt,string textToSave){
    ifstream text(textToDecrypt);
    string decrypted = "";
    ofstream save(textToSave);
    char read;
    text >> std::noskipws >> read;
    while(!text.eof()){
        cout << read;
        HuffmanNode * tmp = m_pTreeRoot;
        while(!tmp->isLeaf){
            if(string(&read) == "1") tmp = tmp->m_pRight;
            else{
                if(string(&read) == "0") tmp = tmp->m_pLeft;
            }
            text >> std::noskipws >> read;
        }
        if (tmp->isLeaf) decrypted += string(&tmp->m_value);
    }
    save << decrypted; text.close(); save.close();
}

void HuffmanCoding::showDot(){
    system("atom tree.dot");
    system("dot -Tpng tree.dot -o tree.png");
    system("open tree.png");
}

void HuffmanCoding::generateDot(string& dot, HuffmanNode* node){
    if (!node) return;
    if (node->m_pLeft)  dot = dot +  to_string(node->m_id) + " -> " + to_string(node->m_pLeft->m_id) + "; \n";
    if (node->m_pRight) dot = dot +  to_string(node->m_id) + " -> " + to_string(node->m_pRight->m_id) + "; \n";
    generateDot(dot,  node->m_pLeft);
    generateDot(dot,  node->m_pRight);
}

void HuffmanCoding::setIDs(HuffmanNode* node, int& i,string& dot){
    if (!node) return;
    node->m_id = i;
    dot = dot + to_string(i) + " [ label = \"" + node->getValFreq() + "\" ]; \n";
    i = i + 1;
    setIDs(node->m_pLeft,i, dot);
    setIDs(node->m_pRight,i, dot);
}

void HuffmanCoding::getDot(){
    string dot = "digraph G {\n";
    int i = 0;
    setIDs(m_pTreeRoot,i,dot);
    generateDot(dot,m_pTreeRoot);
    dot = dot + "}";
    cout << dot<<endl;
    //Generar archivo dot.
    ofstream dotFile;
    dotFile.open("tree.dot");
    dotFile << dot;
    dotFile.close();
}

#endif /* huffmanCoding_h */

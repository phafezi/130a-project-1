#ifndef AUXILIARYHASHTABLE_H
#define AUXILIARYHASHTABLE_H
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>

class AuxiliaryHashTable {
public:
    AuxiliaryHashTable (int q);
    ~AuxiliaryHashTable();
    void insert (std::string element);
    void remove (std::string element);
    bool find (std::string element);
    void print();
private:

    int strToInt(std::string element);
    struct Node {
        std::string info;
        Node *next;
    };

    Node** hashTable = nullptr;
    int size;
};

#endif
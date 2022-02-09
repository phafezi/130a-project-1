#include <fstream>
#include <iostream>
#include <stdio.h>
#include "auxiliaryhashtable.h"

int main(int argc, char** argv){
    AuxiliaryHashTable table = AuxiliaryHashTable(10);
    std::string arr[10] = {"cat", "bat", "dance", "raft", "bang", "land", "great", "bob", "costanza", "Parsa"};
    std::string arr2[10] = {"cat", "rang", "dance", "hats", "bang", "landord", "great", "bobby", "costanza", "ParsaHafezi"};
    std::cout<<"inserting \n";
    for (int i = 0; i < 10; i++)
    {
        table.insert(arr[i]);
    }
    table.print();
    std::cout<<"testing find\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout<< " "<< arr2[i];
        if(table.find(arr2[i])){
            std::cout<< " found ";
        } else {
            std::cout<< " not found ";
        }

    }
    for (int i = 0; i < 10; i++)
    {
        table.remove(arr[i]);
    }
    table.print();
    
}

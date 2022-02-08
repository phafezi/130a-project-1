#include <fstream>
#include <iostream>
#include <stdio.h>
#include "auxiliaryhashtable.h"

int main(int argc, char** argv){
    AuxiliaryHashTable table(10);
    std::string arr[10] = {"cat", "bat", "dance", "raft", "bang", "land", "great", "bob", "costanza", "Parsa"};
    std::string arr2[10] = {"cat", "rang", "dance", "hats", "bang", "landord", "great", "bobby", "costanza", "ParsaHafezi"};
    for (int i = 0; i < 10; i++)
    {
        table.insert(arr[i]);
    }
    table.print();
    std::cout<<"\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout<<table.find(arr2[i]) << " ";
    }
    for (int i = 0; i < 10; i++)
    {
        table.remove(arr[i]);
    }
    table.print();
    
}

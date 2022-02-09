#include "auxiliaryhashtable.h"


AuxiliaryHashTable::AuxiliaryHashTable(int q){
    size = q;
    hashTable = new Node*[q];
    for(int i=0; i<q; i++){
        hashTable[i] = NULL;
    }

}

AuxiliaryHashTable::~AuxiliaryHashTable(){
    
    for(int i=0; i<size; i++){
        Node *n = hashTable[i];
        Node *tmp = NULL;
        while (n != NULL)
        {
            tmp = n->next; 
            delete n; 
            n = tmp;
        }
    }
    delete hashTable;
}

int AuxiliaryHashTable::strToInt( std::string element ){
    unsigned int total, tmp = 0;
    double expo = 0;
    for(int i = 0; i<element.length(); i++){
        expo = std::pow(31,i);
        expo = fmod(expo, size);
        expo = (unsigned int)element[i] * expo;
        expo = fmod(expo, size);
        expo = total + expo;
        expo = fmod(expo, size);
        total = (int)expo;
    }
    return total;
}

void AuxiliaryHashTable::insert (std::string element){
    
    int index = strToInt(element);
    index = index % size;
    if (hashTable[index] == NULL) { // empty list
        hashTable[index] = new Node;
        hashTable[index]->info = element;
        hashTable[index]->next = NULL;
    }
    else {
        Node *n = hashTable[index];
        while (n->next != NULL) 
            n = n->next;
        n->next = new Node;
        n->next->info = element;
        n->next->next = NULL;
    }
}
void AuxiliaryHashTable::remove (std::string element){
    int index = strToInt(element);
    index = index % size;
    if (hashTable[index]->info == element) { // empty list
        Node *tmp = hashTable[index]->next;
        delete hashTable[index];
        hashTable[index] = tmp;
    }
    else {
        Node *p = hashTable[index];
        Node *n = hashTable[index]->next;
        while (n != NULL){
            if (n->info == element) { // empty list
                Node *tmp = n->next;
                delete n;
                p->next = tmp;
                break;
            }
            p = p->next;
            n = n->next;
        }
    }
}

bool AuxiliaryHashTable::find (std::string element){
    int index = strToInt(element);
    Node *n = hashTable[index];
    bool found = false;
    while (n)
    {
        if (n->info == element)
        {
            found = true;
            break;
        }
        n=n->next;
    }
    return found;
    
}

void AuxiliaryHashTable::print(){
    for (int i = 0; i < size; i++)
    {
        std::cout << "\nindex = " << i << "\n=======\n" ;
        Node *n = hashTable[i];
        while (n)
        {
            std::cout << n->info << " ";
            n=n->next;
        }
        
    }
    
}

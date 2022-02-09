#include "bloomFilter.h"

#define prime 2147483647
BloomFilter::BloomFilter( float p , int m, float c , float d ){
    size = Size(p, m, c);
    numHash = numHashFunctions(size, m, d);
    std::cout << "\n size: " << size << "\n numHash " << numHash << "\n";
    bloomFilter.resize(size, false);
    
}
BloomFilter::~BloomFilter(){

}

void BloomFilter::insert(std::string element ){
    //table.remove(element);
    unsigned int intElem = strToInt(element);
    int tmp = 0;
    for(int i = 0; i<numHash; i++){
      tmp = hash(intElem, i);
      bloomFilter[tmp] = true;
    }
}

void BloomFilter::remove(std::string element){
    //table.insert(element);
}

bool BloomFilter::find(std::string element){
    bool found = true;
    unsigned int intElem = strToInt(element);
    int tmp = 0;
    for(int i = 0; i<numHash; i++){
      tmp = hash(intElem, i);
      if(bloomFilter[tmp] == false)
        found = false;
    }
    //if(table.find(element))
        //found = false;
    return found;
}
int BloomFilter::Size(float p , int m, float c){
    double tmp = m*log(p);
    double constant = log(2)*log(2);
    tmp = -tmp/constant;
    tmp = tmp * c;
    return (int)(tmp);
}
int BloomFilter::numHashFunctions(int n , int m, float d){
    double tmp = n* log(2);
    tmp = tmp/m;
    tmp = tmp*d;
    return (int)round(tmp);
}
int BloomFilter::hash(unsigned int element , int index ){
    double tmp, location = 0;
    unsigned int ai, bi = 0;
    srand(index);
    tmp = rand()*(RAND_MAX) + rand() +1;
    ai = fmod(tmp, prime);        
    tmp = rand()*(RAND_MAX) + rand();
    bi = fmod(tmp, prime);
    location = (ai*element) + bi;
    location = fmod(location, prime);
    location = fmod(location, size);
    return (int)location;
}
// String to integer conversion .
// Needed for running the elements on the above hash function .
unsigned int BloomFilter::strToInt(std::string element){
    unsigned int total, tmp = 0;
    double expo = 0;
    for(int i = 0; i<element.length(); i++){
        /*expo = std::pow(31,i);
        expo = fmod(expo, prime);
        expo = (unsigned int)element[i] * expo;
        expo = fmod(expo, prime);
        total = (total + (unsigned int)expo) % prime;*/
        expo = std::pow(31,i);
        expo = fmod(expo, prime);
        expo = (unsigned int)element[i] * expo;
        expo = fmod(expo, prime);
        expo = total + expo;
        expo = fmod(expo, prime);
        total = (unsigned int)expo;
    }
    return total;
}
// Testing
void BloomFilter::print(){
    for (int i = 0; i < size; i++)
    {
        if(bloomFilter[i]==true){
            std::cout<< 1 << " ";
        } else{
            std::cout<< 0 << " ";
        }
    }
    
}
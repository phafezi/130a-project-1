#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

class BloomFilter {

 public:
    BloomFilter();
    ~BloomFilter();                                  // destructor
    void insert(std::string element);
    void remove (std::string element);
    void find (std::string element);
    int bloomFilterSize(int p , int m, int c);
    int numHashFunctions ( int n , int m, int d);
    int hash (unsigned int element , int inde x);
    unsignedint strToInt(std::string element) ;
    void print();
 private:
    int numHashFunctions ( int n , int m, int d);
    int hash (unsigned int element , int inde x);
    unsignedint strToInt(std::string element) ;
    
    
    
};

#endif
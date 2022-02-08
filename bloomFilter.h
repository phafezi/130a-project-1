#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
class BloomFilter {

 public:
   BloomFilter(float p , int m, float c , float d );
   ~BloomFilter();                                  // destructor
   void insert(std::string element);
   void remove (std::string element);
   bool find (std::string element);
   int bloomFilterSize(int p , int m, int c);
   int numHashFunctions (int n , int m, float d);
   unsigned int strToInt(std::string element) ;
   void print();
 private:
   int Size(float p , int m, float c);
   int numHashFunctions ( int n , int m, int d);
   int hash (unsigned int element , int index);
   unsigned int strToInt(std::string element) ;
    
   int* bloomFilter;
   int size;
   int numHash;
    
    
};

#endif
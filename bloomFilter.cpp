
include<math.h>

// Main API o f t h e bloom f i l t e r
// p := p r o b a b i l i t y o f a f a l s e p o s i t i v e
// m := e x p e c t e d number o f s t r i n g s t o be i n s e r t e d
// c := s c a l e f a c t o r o f bloom f i l t e r s i z e
// d := s c a l e f a c t o r o f number o f hash f u n c t i o n s
BloomFilter( int p , int m, f l o a t c , f l o a t d ) ;
// I n s e r t a s t r i n g i n t o t h e bloom f i l t e r .
void BloomFilter::insert(std::string element ){

    
}
// D el e t e an elemen t from t h e bloom f i l t e r .
// Th is w i l l use an a u x i l i a r y hash t a b l e . d e f i n e d bel ow .
void bloomFilter: : remove ( s t d : : s t r i n g elemen t ) ;
// Return t r u e i f t h e elemen t i s in t h e bloom f i l t e r ,
// o t h e r w i s e r e t u r n f a l s e .
bool BloomFilter: : f i n d ( s t d : : s t r i n g elemen t ) ;
// Compute t h e bloom f i l t e r s i z e b a se d on t h e f a l s e p o s i t i v e p r o b a b i l i t y d e s i r e d ,
// and t h e e x p e c t e d number o f s t r i n g s t o be i n s e r t e d .
// S c al e t h e computed s i z e by ’ c ’ ( f o r e x p e r im e n t al p u r p o se s ) .
// p := p r o b a b i l i t y o f a f a l s e p o s i t i v e
// m := e x p e c t e d number o f s t r i n g s t o be i n s e r t e d
// c := s c a l e f a c t o r o f bloom f i l t e r s i z e
int BloomFilter::Size( int p , int m, int c ){
return (m*log(p))/ (log(2)*log(2));
}

int bloomFilter::numHashFunctions ( int n , int m, int d ){
return ((n/m) * log(2));
}


int BloomFilter::hash(unsigned int element , int inde x ) ;

// String to integer conversion .
// Needed for running the elements on the above hash function .
unsigned int s t r T o I n t ( s t d : : s t r i n g elemen t ) ;

// Testing
void Bl o omFil t e r : : p ri n t ( ) ;
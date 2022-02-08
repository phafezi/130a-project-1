#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv){
    
    ifstream setup; 
    setup.open(argv[1]);
    string tmp;
    float p, c, d = 0; 
    int m, i = 0;
    while(getline(setup, tmp)){ //read data from file object and put it into string.
        tmp=tmp.substr(tmp.find(",")+1);
        tmp.substr(0,tmp.find(">"));
        if(i == 0)
            p = std::stof(tmp);
        if(i == 1)
            m = std::stoi(tmp);
        if(i == 2)
            c = std::stof(tmp);
        if(i == 3)
            d = std::stof(tmp);
    }
    // bloomfilter bl = new BloomFilter(p,m,c,d);)
    setup.close();

    ifstream  input;
    input.open(argv[2]);
    ifstream  successfulSearch;
    successfulSearch.open(argv[3]);
    ifstream  failedSearch;
    failedSearch.open(argv[4]);
    ifstream  remove;
    remove.open(argv[5]);

    int in, ss, fs, r, fp, fn = 0;
    for(int phase = 0; phase < 10; phase++){
        
        while(getline(input, tmp) && in < (phase+1)*1000){
            //bl.insert(tmp)
            in++;
        }
        while(getline(successfulSearch, tmp) && ss < (phase+1)*100){
            //if(!bl.find(tmp))
                fn++;
            ss++;
        }

        while(getline(failedSearch, tmp) && fs < (phase+1)*100){
            //if(bl.find(tmp)
                fp++;
            fs++;
        }
        while(getline(remove, tmp) && r < (phase+1)*100){
            //bl.remove(tmp)
            r++;
        }
    }
    input.close();
    successfulSearch.close();
    failedSearch.close();
    remove.close();

    cout<< "bloom filter : false negatives :"<< fn<< "false positive :"<< fp;


}
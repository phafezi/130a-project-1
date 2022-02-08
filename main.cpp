#include <fstream>
#include <iostream>
#include <stdio.h>
#include "bloomFilter.h"
using namespace std;

int main(int argc, char** argv){
    
    ifstream setup; 
    setup.open(argv[1]);
    string tmp;
    float p, c, d = 0; 
    int m, i = 0;
    if (setup.is_open()) {
        cout << "setup open\n";
    } else {
        cout << "setup close\n";
    }
    while(getline(setup, tmp)){ //read data from file object and put it into string.
        tmp=tmp.substr(tmp.find(",")+1);
        tmp=tmp.substr(0,tmp.find(">"));
        if(i == 0){
            cout <<"P string = " << tmp << "\n"; 
            p = std::stof(tmp);
        }
        if(i == 1){
            m = std::stoi(tmp);
            cout <<"M string = " << tmp << "\n"; 
        }
        if(i == 2){
            c = std::stof(tmp);
            cout <<"C string = " << tmp << "\n"; 
        }
        if(i == 3){
            d = std::stof(tmp);
            cout <<"D string = " << tmp << "\n"; 
        }
        i++;
    }

    cout << "P = " << p << "m = " << m << "c = " << c << "d = " << d << "\n";
    BloomFilter bl = BloomFilter(p,m,c,d);
    setup.close();

    ifstream  input;
    input.open(argv[2]);
    ifstream  successfulSearch;
    successfulSearch.open(argv[3]);
    ifstream  failedSearch;
    failedSearch.open(argv[4]);
    ifstream  remove;
    remove.open(argv[5]);


    vector<string> arrInput;
    vector<string> arrSS;
    vector<string> arrFS;
    vector<string> arrRemove;

    while(getline(input, tmp)){
            arrInput.push_back(tmp);
    }
    while(getline(successfulSearch, tmp)){
            arrSS.push_back(tmp);
    }
    while(getline(failedSearch, tmp)){
            arrFS.push_back(tmp);
    }
    while(getline(remove, tmp)){
            arrRemove.push_back(tmp);
    }
    int in = 0;
    int ss = 0;
    int fs = 0;
    int r = 0;
    int fp = 0;
    int fn = 0; 
    for(int phase = 0; phase < 10; phase++){
        cout << "\n phase :" << phase << " in: " << in;
        for (int i = in; i < (phase+1)*1000; i++)
        {
            bl.insert(arrInput[i]);
            in++;
        }
        for (int i = ss; i < (phase+1)*100; i++)
        {
            if(!bl.find(arrSS[i]))
                fp++;
            ss++;
        }
        for (int i = fs; i < (phase+1)*100; i++)
        {
            if(bl.find(arrFS[i]))
                fn++;
            fs++;
        }
        for (int i = r; i < (phase+1)*100; i++)
        {
            bl.remove(arrRemove[i]);
            r++;
        }
        
        
        
    }
    input.close();
    successfulSearch.close();
    failedSearch.close();
    remove.close();

    cout<< "bloom filter : false negatives :"<< fn<< " false positive :"<< fp;
    cout<< "\n input: "<< in << "\n ss: "<< ss << "\n fs: "<< fs << "\n r: "<< r;

}
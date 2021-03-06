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
    vector<string> arrFS_Elem;

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
    int fpTotal = 0;
    int fnTotal = 0; 
    for(int phase = 0; phase < 10; phase++){
        fp = 0;
        fn = 0;
        arrFS_Elem.clear();
        for (int i = in; i < (phase+1)*1000; i++)
        {
            bl.insert(arrInput[i]);
            in++;
        }
        for (int i = ss; i < (phase+1)*100; i++)
        {
            if(!bl.find(arrSS[i]))
                fn++;
            ss++;
        }
        for (int i = fs; i < (phase+1)*100; i++)
        {
            if(bl.find(arrFS[i])){
                fp++;
                arrFS_Elem.push_back(arrFS[i]);

            }
            fs++;
        }
        for (int i = r; i < (phase+1)*100; i++)
        {
            bl.remove(arrRemove[i]);
            r++;
        }
         cout << "\nPhase :" << phase;
         cout<< "\nNumber of false negatives :\n" << fn;
         cout<< "\nNumber of false positives :\n" << fp;
         cout<< "\nProbability of false positives \n" << (float)fp/100 << endl;
        for(auto x: arrFS_Elem){
            cout<< x << endl;
        }
        fpTotal+=fp;
        fnTotal+=fn;
        
        
    }
    input.close();
    successfulSearch.close();
    failedSearch.close();
    remove.close();

    cout<< "\nTotal number of false negatives :\n" << fnTotal<< "\nTotal number of false positive :\n"<< fpTotal << "\nProbability of false positives :\n"<< (float)fpTotal/1000<<endl;


}
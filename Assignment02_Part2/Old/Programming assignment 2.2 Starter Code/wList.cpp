#include "wList.H"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector <string>* buildList () {

    vector <string>* vec = new vector <string>;
    
    string in;

    while (getline(cin, in)) {
        if (in.empty()) break;
        else {
            stringstream strStream(in);
            string word;
            while (strStream >> word) vec->push_back(word);
        }
    }
    return vec;
}
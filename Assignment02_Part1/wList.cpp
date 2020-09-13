#include "wList.H"

using namespace std;

void buildList(vector <string> &words) {
    string line;

    while (getline(cin, line)) {
        if (line.empty()) break;
        else {
            stringstream ss(line);
            string word;
            while (ss >> word) words.push_back(word);
        }
    }
}

#include <vector>
#include <map>
#include <iostream>

using namespace std;

void ECOrderByFrequency(const vector<int> &vecInput, vector<int> &vecDistinct)
{
  // your code goes here 
  map<int, int> freq;

  for (int i = 0; i < vecInput.size(); i++) {
      map<int, int>::iterator it = freq.find(vecInput[i]);
      if (it == freq.end()) freq[vecInput[i]] = 1;
      else freq[vecInput[i]] += 1;
  }

  for (auto &myPair : freq) {
      //cout << myPair.first << ":" << myPair.second << endl;
      vecDistinct.insert(vecDistinct.begin(), myPair.first);
  }
}


int main() {

    vector<int> stest;
    stest.push_back(1);
    stest.push_back(2);
    stest.push_back(5);
    stest.push_back(2);
    stest.push_back(1);
    stest.push_back(1);
    stest.push_back(4);
    vector<int> vtest;
    ECOrderByFrequency(stest, vtest);

    cout << vtest.size() << endl;
    cout << vtest[0] << endl;
    cout << vtest[1] << endl;
    cout << vtest[2] << endl;

    return 1;
}
#include <set>
#include <vector>
using namespace std;

void GetDistinctSubstrings( const std::vector<char> & strInput,
  int k, std::set< std::vector<char> > &setUniqueSubstrings  ) {
// find the set of all distinct length-k substrings in a given string.
// store the set of distinct substrings of length-k 
// in strInput into setUniqueSubstrings
/*
  setUniqueSubstrings.clear();
  if (k == 0) return;
  for (int i = 0; i <= strInput.size() - k; i++) {
    vector <char> temp;
    for (int j = i; j < (i + k); j++) {
      if (j >= strInput.size()) break;
      temp.push_back(strInput[j]);
    }
    setUniqueSubstrings.insert(temp);
  }
  */
  setUniqueSubstrings.clear();
  if ((k == 0) || (strInput.size() == 0)) return;
  for (int i = 0; i <= strInput.size() - k; i++) {
    vector <char> str(strInput.begin() + i, strInput.begin() + i + k);
    setUniqueSubstrings.insert(str);
  }
}

#include <vector>
#include <set>

using namespace std;

void helper( const std::vector<char> & strInput,
  int k, std::set< std::vector<char> > &setUniqueSubstrings  ) {

  for (int i = 0; i <= strInput.size() - k; i++) {
    vector <char> str(strInput.begin() + i, strInput.begin() + i + k);
    setUniqueSubstrings.insert(str);
  }
}


bool IsSubString( const std::vector<char> &strInput, 
  const std::vector<char> &strPattern )
{
  if ((strInput.size() == 0) || (strPattern.size() == 0)) return false;
  if (strPattern.size() > strInput.size()) return false;

  set <vector <char> > mySet;
  int num = strPattern.size();
  vector <char> string1(strInput.begin(), strInput.end());
  helper(string1, num, mySet);

  if (mySet.find(strPattern) != mySet.end()) return true;
  else return false;

}
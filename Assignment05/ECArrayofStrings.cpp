#include <iostream>
#include "ECArrayofStrings.h" 

using namespace std;

ECArrayofStrings :: ECArrayofStrings()
{
}

ECArrayofStrings :: ~ECArrayofStrings()
{
  // your code goes here
  // Nothing to do here?
}

void ECArrayofStrings :: AddString( const string &strToAdd )
{
  setofstrings.push_back(strToAdd);
}

int ECArrayofStrings :: GetNumofStrings() const
{
  int len;
  len = setofstrings.size();
  return len;
}

int ECArrayofStrings :: GetMaxLen() const
{
  int max = 0;
  for (auto k = setofstrings.begin(); k != setofstrings.end(); k++) {
    max = (max > (*k).size()) ? max : (*k).size();
  }
  return max;
}

string ECArrayofStrings :: GetLongestCommonPrefix() const
{
  string prefix = setofstrings[0];
  for (auto k = setofstrings.begin(); k != setofstrings.end(); k++) {
    prefix = GetLongestCommonPrefixofTwo(prefix, (*k));
  }
  return prefix;
}

string ECArrayofStrings :: Concatnate() const
{
  string result;
  for (auto k = setofstrings.begin(); k != setofstrings.end(); k++)
    result += (*k);
  return result;
}

void ECArrayofStrings:: Dump() const
{
  for (auto k = setofstrings.begin(); k != (setofstrings.end() - 1); k++) {
    cout << (*k) << " ";
  }
  cout << *(setofstrings.end() - 1) << endl;
}

string ECArrayofStrings :: GetLongestCommonPrefixofTwo(const string &str1, const string &str2) const
{
  string prefix;
  int len = (str1.size() <= str2.size()) ? str1.size() : str2.size();
  for (int i = 0; i < len; i ++) {
    if (str1[i] == str2[i]) prefix.push_back(str1[i]);
    else return prefix;
  }
  return prefix;
}



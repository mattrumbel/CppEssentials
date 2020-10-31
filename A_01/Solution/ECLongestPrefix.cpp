#include "ECLongestPrefix.h" 
#include <iostream>

using namespace std;

string commonPrefix(string str1, string str2) 
{ 
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Compare str1 and str2 
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
    { 
        if (str1[i] != str2[j]) 
            break; 
        //append to 
        result.push_back(str1[i]); 
    }  
    return (result); 
}
// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  //Begin comparison with first string.
  string prefix =  arrayStrings[0]; 

  for (int i=1; i<=numStrings-1; i++)
  {
    //compare with all remaining stings to find the longest prefix
    prefix = commonPrefix(prefix, arrayStrings[i]); 
  }
  return (prefix); 
}
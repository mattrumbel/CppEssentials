#include <vector>
using namespace std;

void ConcatenateStrings( std::vector<char> &strConcatTo, 
  const std::vector<char> &strConcating  )
{
// Concatenate two strings - 1) strConcatTo 2) strConcating.
// That is, you need to append the string strConcating to
// the end of strConcatTo.
// Result: strConcatTo passed to as input should contain 
// the Concatenated string.

  for (char c : strConcating) {
    strConcatTo.push_back(c);
  }
}

/*
int main() {
  string s1 = "Hello";
  string s2 = "Matt";

  vector <char> s3(s1.begin(), s1.end());
  vector <char> s4(s2.begin(), s2.end());

  ConcatenateStrings(s3, s4);

  for (char c : s3) {
    cout << c << endl;
  }

  return 1;
}
*/
#include "wList.H"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
   vector <string> words;
   buildList(words);

   for (string s : words) cout << s << endl;

   return 0;
}

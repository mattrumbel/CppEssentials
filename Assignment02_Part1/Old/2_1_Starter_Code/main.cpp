#include "wList.H"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
   
   vector <string> words;
   buildList(words);
   
   for (int i = 0; i < words.size(); i++) {
      cout << words[i] << endl;
   }
   
   return 0;
}

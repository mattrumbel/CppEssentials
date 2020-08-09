#include "wList.H"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
   vector <string>* words = buildList();
   
   for (int i = 0; i < words->size(); i++) {
      cout << words->operator[](i) << endl;
   }
   
   delete words;
   return 0;
}

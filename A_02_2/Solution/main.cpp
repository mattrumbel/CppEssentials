#include "wList.H"
#include <string>
#include <list>
#include <iostream>
#include <iomanip>

int main()
{
   using namespace std;
   list<string>* theList = buildList();
   for(auto it = theList->begin();it != theList->end();it++) {
      cout << *it << endl;
   }
   delete theList;
   return 0;
}

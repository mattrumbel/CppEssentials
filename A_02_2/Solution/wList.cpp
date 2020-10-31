#include "wList.H"

#include <iostream>

std::list<std::string>* buildList()
{
   using namespace std;
   list<string>* theList = new list<string>();
   while (cin) {
      string word;
      cin >> word;
      if (cin)
         theList->push_back(word);
   }
   return theList;
}


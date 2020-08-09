#include "ECSort.h" 
#include <vector>
#include <iostream>

using namespace std;

void ECSort(std::vector<int> &vecToSort)
{
  int len = vecToSort.size();
  int i = 1;

  while (i < len) {

    int x = vecToSort[i];
    int j = i - 1;

    while (j >= 0 && vecToSort[j] > x) {
      vecToSort[j+1] = vecToSort[j];
      j -= 1;
    }
    vecToSort[j+1] = x;
    i += 1;
  }
}

/*
int main() {
  vector <int> vec;
  vec.push_back(20);
  vec.push_back(10);
  vec.push_back(30);
  vec.push_back(100);
  vec.push_back(0);
  vec.push_back(33);
  vec.push_back(15);

  ECSort(vec);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
}
*/

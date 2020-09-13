#include <vector>
// #include <iostream>
using namespace std;

// Your first C++ program is here...
int ECBinarySearch(const vector<int> &listNumbers, int value)
{
  // input list of numbers comes as listNumbers vector
  // You need to implement binary search of "value" over this list; 
  // return the position (i.e., array index) of the vector that matches "value"; 
  // or return -1 if not found.

  if (listNumbers.size() == 0) return -1;

  int left = 0;
  int right = listNumbers.size() - 1;
  int mid;

  while (left <= right) {
    mid = left + (right - left) / 2;
    // check middle
    if (listNumbers[mid] == value) return mid;
    // Check right side
    else if (listNumbers[mid] < value) left = mid + 1;
    // Check left side
    else right = mid - 1;
  }
  return -1; 
}

/*
int main() {

  vector <int> vec;
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(9);

  cout << "Location: " << ECBinarySearch(vec, 1) << endl;
  cout << "Location: " << ECBinarySearch(vec, 3) << endl;
  cout << "Location: " << ECBinarySearch(vec, 5) << endl;
  cout << "Location: " << ECBinarySearch(vec, 9) << endl;
  cout << "Location: " << ECBinarySearch(vec, 22) << endl;


  return 0;
}
*/
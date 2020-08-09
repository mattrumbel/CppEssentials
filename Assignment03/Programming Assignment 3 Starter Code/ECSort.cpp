#include <vector>
// #include <iostream>
using namespace std;

void merge (vector <int> &vec, int left, int middle, int right) {

  int left_size = middle - left + 1;
  int right_size = right - middle;
  
  // Create temporary holders
  vector <int> left_vec;
  for (int i = 0; i < left_size; i++) left_vec.push_back(vec[left + i]);
  vector <int> right_vec;
  for (int j = 0; j < right_size; j++) right_vec.push_back(vec[middle + 1 + j]);

  // Merge the split sub-array bad boys
  int left_vec_index = 0;
  int right_vec_index = 0;
  int put_index = left;

  while ((left_vec_index < left_size) && (right_vec_index < right_size)) {

    if (left_vec[left_vec_index] <= right_vec[right_vec_index]) {
      vec[put_index] = left_vec[left_vec_index];
      left_vec_index += 1;
    }
    else { 
      vec[put_index] = right_vec[right_vec_index];
      right_vec_index += 1;
    }
    put_index += 1;
  }

  // Copy left leftover ints
  while (left_vec_index < left_size) {
    vec[put_index] = left_vec[left_vec_index];
    put_index += 1;
    left_vec_index += 1;
  }
  // Copy right leftover ints
  while (right_vec_index < right_size) {
    vec[put_index] = right_vec[right_vec_index];
    put_index += 1;
    right_vec_index += 1;
  }
}

void mergeSort (vector <int> &vec, int left, int right) {

  if (left < right) {
    int middle = left + (right - left) / 2;
    // Recursive call on left half
    mergeSort(vec, left, middle);
    // Recursive call on right half
    mergeSort(vec, middle + 1, right);

    merge(vec, left, middle, right);
  }
}

void ECSort(vector<int> &listInts)
{
  // Sort the numbers in the list

  if ((listInts.size() == 0) || (listInts.size() == 1)) return;

  int left = 0;
  int right = listInts.size() - 1;

  mergeSort(listInts, left, right);

}

/*
int main() {
  vector <int> vec;
  vec.push_back(2);
  vec.push_back(4);
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(5);

  cout << "Before: " << endl;
  for (int n : vec) cout << n << endl;

  ECSort(vec);

  cout << "After: " << endl;
  for (int n : vec) cout << n << endl;
}
*/
#include <vector>
// #include <iostream>
#include <set>
using namespace std;

void EC2SUM(const vector <int> &listNumbers, const vector <int> &listTargets, vector <bool> &list2SUMRes) {

  // False out the progress vector
  int len = listTargets.size();

  // Sure, hold values we know can be added up to, in case
  // of repeats
  for (int targ_ind = 0; targ_ind < len; targ_ind++) {

    set <int> mySet;
    mySet.clear();
    bool found = false;

    for (int num : listNumbers) {

      int temp = listTargets[targ_ind] - num;
      if (mySet.find(temp) != mySet.end()) {
        list2SUMRes.push_back(true);
        found = true;
        ;
      }
      else mySet.insert(num);
    }
    if (!found) list2SUMRes.push_back(false);
  }
}

/*

int main() {

  vector <int> listNumbers;
  listNumbers.push_back(1);
  listNumbers.push_back(2);
  listNumbers.push_back(3);

  // vector <int> tryThis(listNumbers.begin(), listNumbers.end());

  vector <int> listTargets;
  listTargets.push_back(3);
  listTargets.push_back(4);
  listTargets.push_back(9);
  listTargets.push_back(4);

  vector <bool> myBools;
  myBools.push_back(false);
  myBools.push_back(false);
  myBools.push_back(false);

  EC2SUM(listNumbers, listTargets, myBools);

  // for (bool b : myBools) cout << b << endl;

  return 1;
}
*/
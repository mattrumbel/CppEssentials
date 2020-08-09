#include <vector>
using namespace std;

void ECBidirectionSearch( const vector<int> &listNums, int pos, vector<int> &listNumsBS)
{
    // store the numbers in listNums in the order of bidirectional search into listNumsBS
   // pos: initial position of the bidirectional search
   // your code goes here
   int left_index = pos - 1;
   int left_value;
   int right_index = pos + 1;
   int right_value;

   if (listNums.size() == 0 || listNums.size() < pos) return;

   listNumsBS.push_back(listNums[pos]);

   while (true) {
       if (left_index >= 0) left_value = listNums[left_index];
       else left_index = -99;
       if (right_index < listNums.size()) right_value = listNums[right_index];
       else right_index = -99;

       if (left_index != -99 && right_index != -99) {
           listNumsBS.push_back(left_value);
           listNumsBS.push_back(right_value);
       }

       else if (left_index == -99 && right_index != -99) {
           listNumsBS.push_back(right_value);
       }
       else if (left_index != -99 && right_index == -99) {
           listNumsBS.push_back(left_value);
       }
       else {
           return;
       }
       left_index -= 1;
       right_index += 1;
   }
}

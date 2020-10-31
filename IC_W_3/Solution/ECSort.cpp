#include "ECSort.h" 

void ECSort(std::vector<int> &vecToSort)
{
  // perform insertion sort
  for(int i=0; i<(int)vecToSort.size(); ++i)
  {
    int val = vecToSort[i];
    bool fIns = false;
    for(int j=i-1; j>=0; --j)
    {
      if( vecToSort[j] > val )
      {
        vecToSort[j+1] = vecToSort[j];
      }
      else
      {
        vecToSort[j+1] = val;
        fIns = true;
        break;
      }
    }
    if( fIns == false )
    {
      // add the begining
      vecToSort[0] = val;
    }
  } 
}


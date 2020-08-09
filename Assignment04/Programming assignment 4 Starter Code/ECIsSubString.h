#ifndef ECISSUBSTRING_H
#define ECISSUBSTRING_H

#include <vector>
#include <set>

// Determine if string is substring
//void GetDistinctSubstring(const std::vector<char> &strInput, int k,
//   std::set < std::vector<char> > &setUniqueSubstrings);

bool IsSubString( const std::vector<char> &strInput, 
  const std::vector<char> &strPattern );

#endif  // ECISSUBSTRING_H

#include "ECLongestPrefix.h" 
#include <iostream>
#include <string>

using namespace std;

string ECLongestPrefix(int numStrings, const string arrayStrings[]) {

    if (numStrings <= 1) return arrayStrings[0];

    string myStr = arrayStrings[0];
    int len = myStr.length();
    string base = "";

    string longestPrefix_str = "";
    int longestPrefix_len = 0;

    for (int a = 0; a < len; a++) {
        for (int b = a + 1; b < len + 1; b++) {
            base = myStr.substr(a, b);
            if (base.length() > longestPrefix_len) {
                bool isSubstring = true;
                // Iterate through the strings in arrayStrings[1:]
                for (int i = 1; i < numStrings; i++) {
                    if (arrayStrings[i].find(base) == string::npos) {
                        isSubstring = false;
                        break;
                    }
                }
                // We checked all strings for the given substring base
                if (isSubstring) {
                    longestPrefix_str = base;
                    longestPrefix_len = base.length();
                }
            }
        }
    }
    return longestPrefix_str;
}
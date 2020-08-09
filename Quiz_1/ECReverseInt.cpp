//
//  ECReverseInt.cpp
//  
//
//  Created by Yufeng Wu on 11/13/19.
//  Reverse an integer. Assume unsigned.
//

#include <iostream>
#include <string>

using namespace std;

// Reverse an integer (stored in decimal format in a string)
string ECReverseInt(const string &strNumber)
{
    string res = strNumber;
    res.erase(0, res.find_first_not_of('0'));
    
    reverse(res.begin(), res.end());
    return res;
}

/*
int main() {
    string number = "000012304";
    string ret = ECReverseInt(number);
    cout << ret << endl;
    return 1;
}
*/
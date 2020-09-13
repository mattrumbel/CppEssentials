#include "EC2SUM.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
using namespace std;

// File I/O
static void ReadIntsFromFile(const char *filename, vector<int> &listNumbers)
{
  // cout << "Start ReadIntsFromFile Function" << endl;
  // Your code here
  ifstream in_file;
  in_file.open(filename);

  if (!in_file) {
    cout << "Unable to open file: " << filename << endl;
    exit(-1);
  }

  int num;
  while (in_file >> num) listNumbers.push_back(num);

  in_file.close();
  // cout << "End ReadIntsFromFile Function" << endl;
}

// main function
int main( int argc, const char* argv[] )
{
  // cout << "Start Main" << endl;
  // 
  if( argc != 3 )
  {
    // Usage: ./2SUM <number-file> <target-file>
    cout << "Error.  Usage:  ./2SUM <number-file> <target-file> \n";
    exit(1);  
  }

  // read in integers from the first file
  vector<int> listNumbers;
  ReadIntsFromFile( argv[1], listNumbers );

  // read in integers from the seconf file
  vector<int> listTargets;
  ReadIntsFromFile( argv[2], listTargets );

  // 
  vector<bool> listResults;
  // cout << "Before EC2SUM Function Call" << endl;
  EC2SUM(listNumbers, listTargets, listResults);
  // cout << "After EC2SUM Function Call" << endl;

  // dump out results
  cout << "Number of integers in list: " << listNumbers.size() << endl;
  cout << "Nummber of integers to search: " << listTargets.size() << endl;
  for(int i=0; i<(int)listTargets.size(); ++i)
  {
    cout << "Target " << listTargets[i] << ":\t";
    if( listResults[i] )
    {
      cout << "FOUND\n";
    }
    else
    {
      cout << "NOT FOUND\n";
    }
  } 
  // cout << "End Main Function" << endl;
}


//
//  ECTextDocument.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// **********************************************************
// Commands

// your code goes here 

// cmd_InsertTextAt implementation
void cmd_InsertTextAt::Execute() {
  for (int i = 0; i < myChars.size(); i++) myDoc.InsertCharAt(pos + i, myChars[i]);
}

void cmd_InsertTextAt::UnExecute() {
  for (int i = 0; i < myChars.size(); i++) myDoc.RemoveCharAt(pos);
}

// cmd_RemoveTextAt implementation
void cmd_RemoveTextAt::Execute() {
  for (int i = 0; i < length; i++) {
    removedChars.push_back(myDoc.GetCharAt(pos));
    myDoc.RemoveCharAt(pos);
  }
}

void cmd_RemoveTextAt::UnExecute() {
  for (int i = 0; i < removedChars.size(); i++) myDoc.InsertCharAt(pos + i, removedChars[i]);
}

// cmd_CapTextAt implementaion
void cmd_CapTextAt::Execute() {
  for (int i = 0; i < lenToCap; i++) {
    charsBeforeCap.push_back(myDoc.GetCharAt(pos + i));
    myDoc.CapCharAt(pos + i);
  }
}

void cmd_CapTextAt::UnExecute() {
  for (int i = 0; i < lenToCap; i++)
    if (!(myDoc.GetCharAt(pos + i) == charsBeforeCap[i])) myDoc.LowerCharAt(pos + i);
}

// cmd_LowerTextAt implementaion
void cmd_LowerTextAt::Execute() {
  for (int i = 0; i < lenToLower; i++) {
    charsBeforeLower.push_back(myDoc.GetCharAt(pos + i));
    myDoc.LowerCharAt(pos + i);
  }
}

void cmd_LowerTextAt::UnExecute() {
  for (int i = 0; i < lenToLower; i++)
    if (!(myDoc.GetCharAt(pos + i) == charsBeforeLower[i])) myDoc.CapCharAt(pos + i);
}

// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) : doc(docIn)
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  // your code
  histCmds.ExecuteCmd(new cmd_InsertTextAt(pos, listCharsToIns, doc));
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  // your code
  histCmds.ExecuteCmd(new cmd_RemoveTextAt(pos, lenToRemove, doc));
}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
  // your code
  histCmds.ExecuteCmd(new cmd_CapTextAt(pos, lenToCap, doc));
}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
  // your code
  histCmds.ExecuteCmd(new cmd_LowerTextAt(pos, lenToLower, doc));
}

bool ECTextDocumentCtrl :: Undo()
{
  // your code
  return histCmds.Undo();
}

bool ECTextDocumentCtrl :: Redo()
{
  // your code
  return histCmds.Redo();
}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument() : docCtrl(*this)
{
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  // your code here
  listChars.insert(listChars.begin() + pos, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
  // your code here
  listChars.erase(listChars.begin() + pos, listChars.begin() + pos + 1);
}

void ECTextDocument :: CapCharAt(int pos)
{
  // your code here
  // if (isupper(listChars[pos])) listChars[pos] = listChars[pos] - 32;
  if (islower(listChars[pos])) listChars[pos] = toupper(listChars[pos]);
}

void ECTextDocument :: LowerCharAt(int pos)
{
  // your code here
  // if (islower(listChars[pos])) listChars[pos] = listChars[pos] + 32;

  if (isupper(listChars[pos])) listChars[pos] = tolower(listChars[pos]);

}


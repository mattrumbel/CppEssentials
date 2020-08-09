//
//  ECTextDocument.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>

using namespace std;

// **********************************************************
// Implements Commands for editing 


// your code goes here

// Insert text commands
class cmd_InsertTextAt : public ECCommand {
    public:
        cmd_InsertTextAt(int p, const vector<char> &listCharToIns, ECTextDocument &doc) : 
            myChars(listCharToIns), pos(p), myDoc(doc) {};
        void Execute();
        void UnExecute();
    private:
        vector<char> myChars;
        int pos;
        ECTextDocument &myDoc;
};

// Remove text commands
class cmd_RemoveTextAt : public ECCommand {
    public:
        cmd_RemoveTextAt(int p, int l, ECTextDocument &doc) : 
            pos(p), length(l), myDoc(doc) {};
        void Execute();
        void UnExecute();
    private:
        int pos;
        int length;
        vector <char> removedChars;
        ECTextDocument &myDoc;
};

// Cap text at command
class cmd_CapTextAt : public ECCommand {
    public:
        cmd_CapTextAt(int p, int len, ECTextDocument &doc) :
            pos(p), lenToCap(len), myDoc(doc) {};
        void Execute();
        void UnExecute();
    private:
        int pos;
        int lenToCap;
        ECTextDocument &myDoc;
        vector <char> charsBeforeCap;
};

// Lower text at command
class cmd_LowerTextAt : public ECCommand {
    public:
        cmd_LowerTextAt(int p, int len, ECTextDocument &doc) :
            pos(p), lenToLower(len), myDoc(doc) {};
        void Execute();
        void UnExecute();
    private:
        int pos;
        int lenToLower;
        ECTextDocument &myDoc;
        vector <char> charsBeforeLower;
};


// TODO: Add Cap/Lower TextAt classes and implementations
// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn);          // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char> &listCharsToIns);    // insert a list of characters starting at position
    void RemoveTextAt(int pos, int lenToRemove);                            // remove a segment of characters  of lenToRemove starting from pos
    void CapTextAt(int pos, int lenToCap);                                  // Capitalize the text of lenToCap long starting from pos
    void LowerTextAt(int pos, int lenToLower);                              // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                            // undo any change you did to the text
    bool Redo();                                                            // redo the change to the text
    
private:
    ECTextDocument &doc;
    ECCommandHistory histCmds;
};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl();          // return document controller
    int GetDocLen() const { return listChars.size(); }
    char GetCharAt(int pos) const;          // get char at current position
    void InsertCharAt(int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int pos);             // erase a single char at position
    void CapCharAt(int pos);                // capitalize the char at position
    void LowerCharAt(int pos);              // lowercase the char at position
    
private:
    ECTextDocumentCtrl docCtrl;
    std::vector<char> listChars;
};


#endif /* ECTextDocument_h */

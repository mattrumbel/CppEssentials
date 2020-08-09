#ifndef Document_h
#define Document_h

#include <vector>
#include <string>

using namespace std;

class Document {
    public:
        Document(int argc, char *argv[]);
        ~Document();
        // There are several commands to support
        // Character insertion
        void CharInsert(int row, int col, char c);
        void UndoCharInsert(int row, int col);
        // Character deletion
        char CharDelete(int row, int col);
        void UndoCharDelete(int row, int col, char c);
        // Row insertion
        void RowInsert(int row, int col);
        void UndoRowInsert(int row, int col);
        // Row deletion
        int RowDelete(int row);
        void UndoRowDelete(int row, int col);

        void MoveCursorRight();
        void MoveCursorLeft();
        void MoveCursorDown();
        void MoveCursorUp();

        int GetCol();
        int GetRow();

        vector<string> StatusBar();
        vector<string> GetAllLines(int NumRows, int NumCols);

        void PopulateDocument(char *argv[]);
        void WriteToDocument();
        
    private:
        vector<vector<char>*> text;
        int col_track;
        int row_track;
        int total_chars;
        string file_name;
};

#endif
#include "Document.h"
#include <iostream>
#include <fstream>

using namespace std;

Document::Document(int argc, char *argv[]) {
    col_track = 0;
    row_track = 0;
    total_chars = 0;
    if (argc == 2) PopulateDocument(argv);
}

Document::~Document() {
}

void Document::CharInsert(int row, int col, char c) {
    total_chars += 1;
    
    if (text.size() == 0) {
        vector<char> *emptyV = new vector<char>();
        emptyV->push_back(c);
        text.push_back(emptyV);
    } 
    else {
        vector<char> &line = *text[row];
        line.insert(line.begin() + col, c);
    }
    col_track += 1;
    row_track = row;
}

void Document::UndoCharInsert(int row, int col) {
    total_chars -= 1;
    vector<char> &line = *text[row];
    line.erase(line.begin() + col);
    
    if (col == 0) col_track = 0;
    else col_track = col;
    row_track = row;
}

char Document::CharDelete(int row, int col) {
    vector<char> &line = *text[row];
    if (line.size() == 0) return 0;     // 0 will indicate nothing was deleted
    total_chars -= 1;
    char c = line[col - 1];

    line.erase(line.begin() + col - 1);
    row_track = row;

    if (col == 0) col_track = 0;
    else col_track = col - 1;
    row_track = row;
    return c;

    return 'X';
}

void Document::UndoCharDelete(int row, int col, char c) {
    total_chars += 1;
    vector<char> &line = *text[row];
    line.insert(line.begin() + col - 1, c);
    
    col_track += 1;
    row_track = row;
}

void Document::RowInsert(int row, int col) {
    if (text.size() == 0) {
        text.push_back(new vector<char>());
        text.push_back(new vector<char>());
        row_track = 1;
        col_track = 0;
    } else if (col == 0) {
        vector<char> *v = new vector<char>();
        text.insert(text.begin() + row, v);
        row_track = row + 1;
        col_track = 0;
    } else {
        vector<char> &line = *text[row];
        vector<char> *right = new vector<char>();
        for (int i = col; i < line.size(); i++) right->push_back(line[i]);
        line.erase(line.begin() + col, line.end());
        if (row == text.size() - 1) text.push_back(right);
        else text.insert(text.begin() + row + 1, right);
        row_track = row + 1;
        col_track = 0;
    }
}

void Document::UndoRowInsert(int row, int col) {
    vector<char> &line_to_add_to = *text[row];
    col_track = line_to_add_to.size();
    vector<char> &line_to_pull_from = *text[row + 1];
    for (char c : line_to_pull_from) line_to_add_to.push_back(c);
    text.erase(text.begin() + row + 1);
    row_track = row;
}

int Document::RowDelete(int row) {
    vector<char> &line_to_add_to = *text[row - 1];
    col_track = line_to_add_to.size();
    vector<char> &line_to_pull_from = *text[row];
    for (char c : line_to_pull_from) line_to_add_to.push_back(c);
    text.erase(text.begin() + row);

    row_track = row - 1;
    return col_track;
}

void Document::UndoRowDelete(int row, int col) {
    vector<char> *line_to_add_to = new vector<char>();
    vector<char> &line_to_pull_from = *text[row - 1];
    for (int i = col; i < line_to_pull_from.size(); i++) line_to_add_to->push_back(line_to_pull_from[i]);
    text.insert(text.begin() + row, line_to_add_to);
    
    col_track = 0;
    row_track = row;
}

void Document::MoveCursorRight() {
    if (text.size() == 0) return;
    if (col_track == text[row_track]->size()) {
        // Right most position on a line
        if (row_track < text.size() - 1) {
            row_track += 1;
            col_track = 0;
        } else {
            // Do nothing
        }
    } else {
        col_track += 1;
    }
}

void Document::MoveCursorLeft() {
    if (text.size() == 0) return;
    if (col_track == 0) {
        // left-most position on a line
        if (row_track == 0) return;
        else {
            col_track = text[row_track - 1]->size();
            row_track -= 1;
        }
    } else {
        col_track -= 1;
    }
}

void Document::MoveCursorUp() {
    if (text.size() == 0) return;
    if (row_track == 0) return;
    else {
        int above_row_len = text[row_track - 1]->size();
        
        row_track -= 1;
        if (col_track > above_row_len) col_track = above_row_len;
        else  {} // Don't need to do anything
    }
}

void Document::MoveCursorDown() {
    if (text.size() == 0) return;
    if (row_track == text.size() - 1) return;
    else {
        int below_row_len = text[row_track + 1]->size();

        row_track += 1;
        if (col_track > below_row_len) col_track = below_row_len;
        else {} // Don't need to do anything
    }
}

int Document::GetCol() {return col_track;}
int Document::GetRow() {return row_track;}

vector<string> Document::StatusBar() {
    int total_rows = text.size();
    // /No longer needed, keep track of characters when insert/delete
    // int total_chars_c = 0;
    // for (vector<char> *line : text) {
    //     total_chars_c += line->size();
    // }
    // string left = "Lines:" + to_string(total_rows) + " Chars:" + to_string(total_chars_c);
    string right = "Lines:" + to_string(total_rows) + " Chars:" + to_string(total_chars);
    string left = "CursorLoc: Line:" + to_string(row_track + 1) + " Col: " + to_string(col_track);

    vector<string> sb;
    sb.push_back(left);
    sb.push_back(right);
    return sb;
}

vector<string> Document::GetAllLines(int NumRows, int NumCols) {
    vector<string> vs;
    vector<char> vc;
    for (vector<char>* v : text) {
        vc = *v;
        string str(vc.begin(), vc.end());
        vs.push_back(str);
    }

    // vector<string> vs;
    // vector<char> vc;
    // int start_index = NumRows * (row_track / NumRows);
    // for (int i = start_index; (i < (start_index + NumRows)) && (i < text.size()); i++) {
    //     vc = *text[i];
    //     string str(vc.begin(), vc.end());
    //     vs.push_back(str);
    // }

    return vs;
}

void Document::PopulateDocument(char *argv[]) {
    file_name = argv[1];
    ifstream file(argv[1]);
    if (file.is_open()) {
        string line;
        int line_number = 0;
        int col_number = 0;

        getline(file, line);
        if (file.eof()) return;

        while (true) {
            for (char c : line) {
                CharInsert(line_number, col_number, c);
                col_number += 1;
            }
            getline(file, line);
            if (!file.eof()) {
                RowInsert(line_number, col_number);
                line_number += 1;
                col_number = 0;
            } else {
                RowDelete(line_number);
                break;
            };
        }
    }
    file.close();
    if (text.size() == 0) {
        row_track = 0;
        col_track = 0;
    }
    else {
        row_track = text.size() - 1;
        col_track = text[row_track]->size();
    }
}

void Document::WriteToDocument() {
    // Open and clear document
    ofstream file;
    string str;
    file.open(file_name, fstream::out | fstream::trunc);
    for (int char_v_i = 0; char_v_i < text.size(); char_v_i++) {
        for (char c : *text[char_v_i]) {
            str.push_back(c);
        }
        file << str << endl;
        str.clear();
    }
    file.close();
}
#include "EditorController.h"
#include <iostream>
#include <string>

using namespace std;

EditorController::EditorController() {
    doc = new Document();
    command_history = new CommandHistory();
    sb = new cmd_StatusBar(doc);
    view_imp = new ECTextViewImp();
    view_imp->Attach(this);
    view_imp->Show();
    view_imp->SetCursorX(0);
    view_imp->SetCursorY(0);
    view_imp->ClearStatusRows();
    vector<string> info = sb->GetInfo();
    view_imp->AddStatusRow(info[0], info[1], true);
    view_imp->Refresh();
}

EditorController::~EditorController() {
    view_imp->Detach(this);
    delete view_imp;
    delete command_history;
}

void EditorController::Update() {
    int curr_x = view_imp->GetCursorX();
    int curr_y = view_imp->GetCursorY();
    int key = view_imp->GetPressedKey();

    if ((key >= 32) && (key <= 126)) {
        // Regular symbol
        char c = key;
        InsertChar(curr_y, curr_x, c);
        clear_redo_history = true;
    } else if (key == 127) {
        // Backspace
        DeleteChar(curr_y, curr_x);
        clear_redo_history = true;
    } else if (key == 13) {
        // Enter
        InsertRow(curr_y, curr_x);
        clear_redo_history = true;
    } else if (key == 26) {
        // Undo
        Undo();
    } else if (key == 25) {
        // Redo
        Redo();
    }
    // Arrow keys
    else if (key == 1000) {ArrowLeft();} 
    else if (key == 1001) {ArrowRight();}
    else if (key == 1002) {ArrowUp();}
    else if (key == 1003) {ArrowDown();}
    else {}

    if (clear_redo_history == true) ClearRedo();
    FillDocument();
}
void EditorController::InsertChar(int row, int col, const char charToInsert) {
    command_history->ExecuteCommand(new cmd_CharInsert(row, col, charToInsert, doc));
}

void EditorController::DeleteChar(int row, int col) {
    if (col == 0 && row != 0) DeleteRow(row);
    else command_history->ExecuteCommand(new cmd_CharDelete(row, col, doc));
}

void EditorController::InsertRow(int row, int col) {
    command_history->ExecuteCommand(new cmd_RowInsert(row, col, doc));
}

void EditorController::DeleteRow(int row) {
    command_history->ExecuteCommand(new cmd_RowDelete(row, doc));
}

void EditorController::FillDocument() {
    view_imp->InitRows();
    view_imp->ClearStatusRows();
    vector<string> info = sb->GetInfo();
    view_imp->AddStatusRow(info[0], info[1], false);
    // view_imp->AddRow("");
    vector<string> all_lines = doc->GetAllLines();
    for (string s : all_lines) view_imp->AddRow(s);
    view_imp->SetCursorX(doc->GetCol());
    view_imp->SetCursorY(doc->GetRow());

    // view_imp->AddRow("Doc Lines:");
    // view_imp->AddRow(to_string(doc->GetCol()));
    // view_imp->AddRow(to_string(doc->GetRow()));
    
    view_imp->Refresh();
}

void EditorController::Undo() {
    command_history->Undo();
}

void EditorController::Redo() {
    command_history->Redo();
}

void EditorController::SetStatusBar() {
    // Not needed at the moment
    cmd_StatusBar cmd = cmd_StatusBar(doc);
    vector<string> info = cmd.GetInfo();
    view_imp->AddStatusRow(info[0], info[1], true);
}

void EditorController::ArrowLeft() {
    cmd_ArrowLeft cmd = cmd_ArrowLeft(doc);
    cmd.Execute();
}

void EditorController::ArrowRight() {
    cmd_ArrowRight cmd = cmd_ArrowRight(doc);
    cmd.Execute();
}

void EditorController::ArrowDown() {
    cmd_ArrowDown cmd = cmd_ArrowDown(doc);
    cmd.Execute();
}

void EditorController::ArrowUp() {
    cmd_ArrowUp cmd = cmd_ArrowUp(doc);
    cmd.Execute();
}

void EditorController::ClearRedo() {
    command_history->ClearRedo();
    clear_redo_history = false;
}
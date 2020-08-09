#include <iostream>
#include "Commands.h"


// Character insertion
cmd_CharInsert::cmd_CharInsert(int line, int col, char c, Document *d) : lineNumber(line), colNumber(col), c(c), doc(d) {}
void cmd_CharInsert::Execute() {
  doc->CharInsert(lineNumber, colNumber, c);
}
void cmd_CharInsert::UnExecute() {
  doc->UndoCharInsert(lineNumber, colNumber);
}


// Character deletion
cmd_CharDelete::cmd_CharDelete(int line, int col, Document* d) : lineNumber(line), colNumber(col), doc(d) {}
void cmd_CharDelete::Execute() {
  c = doc->CharDelete(lineNumber, colNumber);
}
void cmd_CharDelete::UnExecute() {
  if (c != 0) doc->UndoCharDelete(lineNumber, colNumber, c);
}


// Row insertion
cmd_RowInsert::cmd_RowInsert(int line, int c, Document *d) : lineNumber(line), col(c), doc(d) {};
void cmd_RowInsert::Execute() {
  doc->RowInsert(lineNumber, col);
}
void cmd_RowInsert::UnExecute() {
  doc->UndoRowInsert(lineNumber, col);
}


// Row deletion
cmd_RowDelete::cmd_RowDelete(int r, Document *d) : row(r), doc(d) {};
void cmd_RowDelete::Execute() {
  col = doc->RowDelete(row);
}
void cmd_RowDelete::UnExecute() {
  doc->UndoRowDelete(row, col);
}


// Arrow key
cmd_ArrowRight::cmd_ArrowRight(Document *d) : doc(d) {};
cmd_ArrowLeft::cmd_ArrowLeft(Document *d) : doc(d) {};
cmd_ArrowUp::cmd_ArrowUp(Document *d) : doc(d) {};
cmd_ArrowDown::cmd_ArrowDown(Document *d) : doc(d) {};

void cmd_ArrowRight::Execute() {doc->MoveCursorRight();}
void cmd_ArrowLeft::Execute() {doc->MoveCursorLeft();}
void cmd_ArrowUp::Execute() {doc->MoveCursorUp();}
void cmd_ArrowDown::Execute() {doc->MoveCursorDown();}


// Status bar
cmd_StatusBar::cmd_StatusBar(Document *d) : doc(d) {};
vector<string> cmd_StatusBar::GetInfo() {return doc->StatusBar();}


// Command History
CommandHistory::CommandHistory() {
    cmd_hist_redo = new stack <Command*>;
    cmd_hist_undo = new stack <Command*>;
}

CommandHistory::~CommandHistory() {
    while (!(cmd_hist_undo->empty())) cmd_hist_undo->pop();
    delete cmd_hist_undo;

    while (!(cmd_hist_redo->empty())) cmd_hist_redo->pop();
    delete cmd_hist_redo;
}

void CommandHistory::Undo() {
  if (!(cmd_hist_undo->empty())) {
        cmd_hist_undo->top()->UnExecute();
        Command* cmd_to_mv = cmd_hist_undo->top();
        cmd_hist_redo->push(cmd_to_mv);
        cmd_hist_undo->pop();
  }
}

void CommandHistory::Redo() {
  if (!(cmd_hist_redo->empty())) {
        cmd_hist_redo->top()->Execute();
        Command* cmd_to_mv = cmd_hist_redo->top();
        cmd_hist_undo->push(cmd_to_mv);
        cmd_hist_redo->pop();
  }
}

void CommandHistory::ExecuteCommand(Command *cmd) {
      cmd->Execute();
      cmd_hist_undo->push(cmd);
}

void CommandHistory::ClearUndo() {
  // Shouldn't need at moment
  while (!(cmd_hist_undo->empty())) cmd_hist_undo->pop();
}
void CommandHistory::ClearRedo() {
  while (!(cmd_hist_redo->empty())) cmd_hist_redo->pop();
}
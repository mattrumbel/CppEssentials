//
//  ECCommand.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory() 
{
  // your code goes here
  cmd_hist_undo = new stack <ECCommand*>;
  cmd_hist_redo = new stack <ECCommand*>;
}

ECCommandHistory :: ~ECCommandHistory()
{
  // your code goes here
  while (!(cmd_hist_undo->empty())) cmd_hist_undo->pop();
  delete cmd_hist_undo;

  while (!(cmd_hist_redo->empty())) cmd_hist_redo->pop();
  delete cmd_hist_redo;
}

bool ECCommandHistory :: Undo() {
  if (!(cmd_hist_undo->empty())) {
    cmd_hist_undo->top()->UnExecute();
    ECCommand* cmd_to_mv = cmd_hist_undo->top();
    cmd_hist_redo->push(cmd_to_mv);
    cmd_hist_undo->pop();
    return true;
  } else return false;
}

bool ECCommandHistory :: Redo() {
  if (!(cmd_hist_redo->empty())) {
    cmd_hist_redo->top()->Execute();
    ECCommand* cmd_to_mv = cmd_hist_redo->top();
    cmd_hist_undo->push(cmd_to_mv);
    cmd_hist_redo->pop();
    return true;
  } else return false;
}

void ECCommandHistory :: ExecuteCmd(ECCommand *pCmd) {
  pCmd->Execute();
  cmd_hist_undo->push(pCmd);
}

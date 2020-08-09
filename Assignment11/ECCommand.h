//
//  ECCommand.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECCommand_h
#define ECCommand_h

#include <vector>
#include <stack>

// ******************************************************
// Implement command design pattern

using namespace std;

class ECCommand
{
public:
    virtual ~ECCommand() {};
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory();
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    
private:
    // your code goes here
    stack <ECCommand*> *cmd_hist_undo;
    stack <ECCommand*> *cmd_hist_redo;
};


#endif /* ECCommand_h */

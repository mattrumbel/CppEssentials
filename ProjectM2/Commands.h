#ifndef Commands_h
#define Commands_h

#include <stack>
#include "Document.h"

using namespace std;

class Command {
    public:
        virtual ~Command() {};
        virtual void Execute() = 0;
        virtual void UnExecute() = 0;
};

class cmd_CharInsert: public Command {
    public:
        cmd_CharInsert(int lineNumber, int colNumber, char c, Document *doc);
        ~cmd_CharInsert() {};
        void Execute();
        void UnExecute();
    private:
        int lineNumber;
        int colNumber;
        char c;
        Document *doc;
};

class cmd_CharDelete: public Command {
    public:
        cmd_CharDelete(int lineNumber, int colNumber, Document *doc);
        ~cmd_CharDelete() {};
        void Execute();
        void UnExecute();
    private:
        int lineNumber;
        int colNumber;
        Document* doc;
        char c;
};

class cmd_RowInsert : public Command {
    public:
        cmd_RowInsert(int lineNumber, int col, Document *doc);
        ~cmd_RowInsert() {};
        void Execute();
        void UnExecute();
    private:
        int lineNumber;
        int col;
        Document *doc;
};

class cmd_RowDelete : public Command {
    public:
        cmd_RowDelete(int row, Document *doc);
        ~cmd_RowDelete() {};
        void Execute();
        void UnExecute();
    private:
        int row;
        int col;
        Document *doc;
};

class cmd_ArrowLeft : public Command {
    public:
        cmd_ArrowLeft(Document* doc);
        ~cmd_ArrowLeft() {};
        void Execute();
        void UnExecute() {};
    private:
        Document* doc;
};

class cmd_ArrowRight : public Command {
    public:
        cmd_ArrowRight(Document *doc);
        ~cmd_ArrowRight() {};
        void Execute();
        void UnExecute() {};
    private:
        Document* doc;
};

class cmd_ArrowDown : public Command {
    public:
        cmd_ArrowDown(Document *doc);
        ~cmd_ArrowDown() {};
        void Execute();
        void UnExecute() {};
    private:
        Document *doc;
};

class cmd_ArrowUp : public Command {
    public:
        cmd_ArrowUp(Document *doc);
        ~cmd_ArrowUp() {};
        void Execute();
        void UnExecute() {};
    private:
        Document *doc;
};

class cmd_StatusBar : public Command {
    public:
        cmd_StatusBar(Document *doc);
        ~cmd_StatusBar() {};
        void Execute() {};
        vector<string> GetInfo();
        void UnExecute() {};
    private:
        Document *doc;
};

class CommandHistory {
    public:
        CommandHistory();
        virtual ~CommandHistory();
        void ClearRedo();
        void ClearUndo();
        void Undo();
        void Redo();
        void ExecuteCommand(Command *cmd);
    private:
        stack <Command*> *cmd_hist_undo;
        stack <Command *> *cmd_hist_redo;
};

#endif
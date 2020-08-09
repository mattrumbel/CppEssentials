#ifndef EditorController_h
#define EditorController_h

#include "ECObserver.h"
#include "Commands.h"
#include "ECTextViewImp.h"
#include "Document.h"

using namespace std;

class EditorController : public ECObserver {
    public:
        EditorController(int argc, char *argv[]);
        ~EditorController();
        void Update();
        void InsertChar(int row, int col, const char charToInsert);
        void DeleteChar(int row, int col);
        void InsertRow(int row, int col);
        void DeleteRow(int row);
        void FillDocument(int NumRows, int NumCols);
        void Undo();
        void Redo();
        void SetStatusBar();
        void ArrowLeft();
        void ArrowRight();
        void ArrowUp();
        void ArrowDown();
        void ClearRedo();
        void SaveDocument();
    private:
        ECTextViewImp *view_imp;
        CommandHistory *command_history;
        Document *doc;
        cmd_StatusBar *sb;
        bool clear_redo_history;
};

#endif
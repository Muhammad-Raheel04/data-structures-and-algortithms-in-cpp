#include<iostream>
#include<string>
using namespace std;

#define MAX 100

class UndoRedo{
private:
   string undoStack[MAX];  
   string redoStack[MAX];
   
   int undoTop;
   int redoTop;

   string currentText;
public:
    UndoRedo(){
        undoTop=-1;
        redoTop=-1;
        currentText="";
    }   
    void pushUndo(string text){
        if(undoTop<MAX-1){
            undoStack[++undoTop]=text;
        }
    }
    void pushRedo(string text){
        if(redoTop<MAX-1){
            redoStack[++redoTop]=text;
        }
    }
    string popUndo(){
        if(undoTop>=0){
            return undoStack[undoTop--];
        }
        return "";
    }
    string popRedo(){
        if(redoTop>=0){
            return redoStack[redoTop--];
        }
        return "";
    }
    void insertText(string text){
        pushUndo(currentText);

        redoTop=-1;

        currentText+=text;

        cout<<"Inserted: "<<text<<endl;
        showText();
    }
    void deleteText(int pos,int len){
        if(pos>=currentText.size()){
            return;
        }

        pushUndo(currentText);

        redoTop=-1;
        currentText.erase(pos,len);

        cout<<"Deleted text"<<endl;
        showText();
    }

    void undo(){
        if(undoTop==-1){
            cout<<"Nothing to undo"<<endl;
            return;
        }

        pushRedo(currentText);
        currentText=popUndo();

        cout<<"Undo performed"<<endl;
        showText();
    }
    void redo(){
        if(redoTop==-1){
            cout<<"Nothing to redo"<<endl;
            return;
        }

        pushUndo(currentText);
        currentText=popRedo();

        cout<<"Redo performed"<<endl;
        showText();
    }
    void showText(){
        cout<<"Current Text"<<endl;
        cout<<currentText<<endl;
    }
};
int main(){
    UndoRedo ur;

    ur.insertText("JavaScript");
    ur.insertText(" is");
    ur.insertText(" love");

    ur.undo();
    
    ur.redo();

    ur.deleteText(11,18);

    ur.undo();
    return 0;
}
#include<iostream>
#include<string>

#define MAX 100
using namespace std;

class BrowserNavigation{
private:
   string backStack[MAX];
   int backTop;

   string forwardStack[MAX];
   int forwardTop;

   string currentPage;
public:
   BrowserNavigation(){
    backTop=-1;
    forwardTop=-1;
    currentPage="Home";
   }   
   bool isBackEmpty(){
    return backTop==-1;
   }
   bool isBackFull(){
    return backTop==MAX-1;
   }
   bool isForwardEmpty(){
    return forwardTop==-1;
   }
   bool isForwardFull(){
    return forwardTop==MAX-1;
   }
   void pushBack(string page){
    if(!isBackFull()){
        backStack[++backTop]=page;
    }
   }
   void pushForward(string page){
    if(!isForwardFull()){
        forwardStack[++forwardTop]=page;
    }
   }
   string popBack(){
    if(backTop>=0){
        return backStack[backTop--];
    }
    return "";
   }
   string popForward(){
    if(forwardTop>=0){
        return forwardStack[forwardTop--];
    }
    return "";
   }
   void visitNewPage(string page){
    pushBack(currentPage);

    forwardTop=-1;

    currentPage=page;
    cout<<"Visited: "<<currentPage<<endl;
   }
   void goBack(){
    if(isBackEmpty()){
        cout<<"No previous page"<<endl;
        return;
    }
    pushForward(currentPage);
    currentPage=popBack();

    cout<<"Went back to: "<<currentPage<<endl;
   }
   void goForward(){
    if(isForwardEmpty()){
        cout<<"No forward pages"<<endl;
        return;
    }
    pushBack(currentPage);
    currentPage=popForward();

    cout<<"Went forward to "<<currentPage<<endl;
   }
   void showCurrentPage(){
    cout<<"Current page "<<currentPage<<endl;
   }
};
int main(){
  BrowserNavigation bn;

    bn.showCurrentPage();

    bn.visitNewPage("google.com");
    bn.visitNewPage("youtube.com");
    bn.visitNewPage("github.com");

    bn.goBack();
    bn.goBack();

    bn.goForward();
    bn.goForward();

    bn.visitNewPage("stackoverflow.com");
}
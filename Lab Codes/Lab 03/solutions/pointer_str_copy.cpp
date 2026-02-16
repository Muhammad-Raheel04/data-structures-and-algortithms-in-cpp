#include<iostream>
#include<cstring>
using namespace std;

void strCopy(char *p1,char *p2,int size){
    for(int i=0;i<size;i++){
        *(p2+i)=*(p1+i);
    }
    cout<<endl;
}
void printStr(char *p,int size){
     for(int i=0;i<size;i++){
        cout<<*(p+i);
     }
    cout<<endl;
}
int main(){
    char str1[]="Muhammad Raheel";
    cout<<"Printing String 1"<<endl;
    printStr(str1,strlen(str1));
    char str2[strlen(str1)];
    cout<<"Doing copy...";
    strCopy(str1,str2,strlen(str1));
    cout<<"Printing String 2"<<endl;
    printStr(str2,strlen(str2));
    return 0;
}
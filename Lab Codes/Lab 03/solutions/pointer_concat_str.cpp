#include<iostream>
#include<cstring>
using namespace std;

void concatStr(char *p1,char *p2,char *dest){
    while(*p1!='\0'){
        *dest=*p1;
        dest++;
        p1++;
    }
    while(*p2!='\0'){
        *dest=*p2;
        dest++;
        p2++;
    }
    cout<<endl;
}
void printStr(char *p,int size){
     while(*p!='\0'){
        cout<<*p;
        p++;
     }
    cout<<endl;
}
int main(){
    char str1[]="Muhammad ";
    char str2[]="Raheel";
    char dest[20]; 
    cout<<"Printing String 1"<<endl; 
    printStr(str1,strlen(str1));
    cout<<"Printing String 2"<<endl;
    printStr(str2,strlen(str2)); 
    cout<<"Concatenating...";   
    concatStr(str1,str2,dest);
    cout<<"Printing concatenated String"<<endl;
    printStr(dest,strlen(dest));
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
void printString(char *p,int size){
     for(int i=0;i<size;i++){
        cout<<*(p+i);
     }
}
int main(){ 
    char str[]="Muhammd Raheel";
    printString(str,strlen(str));
    return 0;
}
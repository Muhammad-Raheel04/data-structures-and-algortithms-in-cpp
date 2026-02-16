#include<iostream>
using namespace std;
int strLength(char *p){
    int count=0;
    while(*p!='\0'){
        count++;
        p++;
    }
    return count;
}
int main(){
    char str[]="Muhammad Raheel";
    cout<<"String Length = "<<strLength(str);
}
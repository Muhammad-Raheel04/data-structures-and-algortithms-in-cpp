#include<iostream>
using namespace std;

int main(){
    int a=10,*p;
    cout<<"Value of a before assignment = "<<a<<endl;
    p=&a;
    *p=3; // assigning 10 to a using pointer
    cout<<"Value of a after assignment = "<<a;
    return 0;
}

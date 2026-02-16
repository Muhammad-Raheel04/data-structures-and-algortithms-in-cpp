#include<iostream>
using namespace std;

int main(){
    int a,b,*p1,*p2;
    a=10;
    b=20;
    p1=&a;
    p2=&b;

    cout<<"Value of a = "<<a<<endl;
    cout<<"Address of a = "<<p1<<endl;
    cout<<"Value of b = "<<b<<endl;
    cout<<"Address of b = "<<p2<<endl;
    
    return 0;
}
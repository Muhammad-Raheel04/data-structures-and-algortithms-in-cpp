#include<iostream>
using namespace std;
void tempConverter(int *p1,int *p2){
    *p2=(5.0/9)*(*p1-32);
}
int main(){
    int f=98,c,*p1,*p2;
    p1=&f;
    cout<<"Temperature in fahrenheit = "<<*p1<<endl;
    p2=&c;
    tempConverter(p1,p2);
    cout<<"Temperature in Celsius = "<<*p2<<endl;
    return 0;
}
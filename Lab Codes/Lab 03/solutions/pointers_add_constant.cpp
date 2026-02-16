#include<iostream>
using namespace std;
void addConstant(int *p1,int *p2){
    *p1+=100;
    *p2+=100;
}
int main(){
    int a=1,b=2,*p1,*p2;
    p1=&a;
    p2=&b;
    cout<<"Value of a before increment = "<<*p1<<endl;
    cout<<"Value of b before increment = "<<*p2<<endl;
    addConstant(p1,p2);
    cout<<"Value of a after increment = "<<*p1<<endl;
    cout<<"Value of b after increment = "<<*p2<<endl;

    return 0;

}
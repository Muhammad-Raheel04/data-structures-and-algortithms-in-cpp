#include<iostream>
using namespace std;
void swapValues(int *p1,int *p2){
    swap(*p1,*p2);
}
int main(){
    int a=1,b=2,*p1,*p2;
    p1=&a;
    p2=&b;
    cout<<"Value of a before swaping = "<<*p1<<endl;
    cout<<"Value of b before swaping = "<<*p2<<endl;
    cout<<endl;
    swapValues(p1,p2);
    cout<<"Value of a after increment = "<<*p1<<endl;
    cout<<"Value of b after increment = "<<*p2<<endl;

    return 0;

}
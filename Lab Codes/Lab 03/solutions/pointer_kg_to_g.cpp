#include<iostream>
using namespace std;
double kgToGram(double *p){
  return (*p)*1000.0;
}
int main(){
    double weight=64.3;
    cout<<"Weight in kg = "<<weight<<endl;
    cout<<"Weight in grams = "<<kgToGram(&weight);
    return 0;
}
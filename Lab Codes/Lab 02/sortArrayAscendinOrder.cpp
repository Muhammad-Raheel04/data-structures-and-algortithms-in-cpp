#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};

    int length=sizeof(arr)/sizeof(arr[0]);
   
    for(int i=0;i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int length=sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Enter a number to search ";
    cin>>k;

    bool found;
    int index;
    for(int i=0;i<length-1;i++){
        if(k==arr[i]){
            found=true;
            index=i;
            break;
        }
    }
    if(found){
        cout<<"Element found at index "<<index;
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}
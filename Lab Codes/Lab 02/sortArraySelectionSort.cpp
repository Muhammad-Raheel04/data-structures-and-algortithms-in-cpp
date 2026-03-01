#include <iostream>
using namespace std;

int main(){
    int arr[5]={5,4,3,2,1};
    int length=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<length-1;i++){
        int minIndex=i;

        for(int j=i+1;j<length;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }

        swap(arr[i],arr[minIndex]);
    }

    cout<<"Sorted Array ";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
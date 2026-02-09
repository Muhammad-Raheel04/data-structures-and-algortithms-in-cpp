#include<iostream>
using namespace std;
void nextInLine(int arr[], int size,int num) {
	for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=num;
}
int main(){
    int arr[]={1,2,3,4};
    int size=4;
    nextInLine(arr,size,7);
    // nextInLine(arr,size,6);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
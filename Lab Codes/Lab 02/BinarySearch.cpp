#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,};
    int n=5;
    int key;

    cout<<"Enter a number to search ";
    cin>>key;

    int start=0;
    int end=n-1;
    int mid;
    int found=-1;

    while(start<=end){
        mid=(start+end)/2;

        if(arr[mid]==key){
            found=mid;
            break;
        }

        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(found!=-1){
        cout<<"Element found at index "<<found;
    }
    else{
        cout<<"Element not found";
    }
}
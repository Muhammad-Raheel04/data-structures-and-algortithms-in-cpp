#include <iostream>
#include <string>
using namespace std;

int main(){
    string unSortedStr="eA2a1E";
    
    for(int i=0;i<unSortedStr.size();i++){
        for(int j=0;j<unSortedStr.size()-i-1;j++){
            if(unSortedStr[j]>unSortedStr[j+1]){
                swap(unSortedStr[j],unSortedStr[j+1]);
            }
        }
    }
    cout<<unSortedStr;
    return 0;
}
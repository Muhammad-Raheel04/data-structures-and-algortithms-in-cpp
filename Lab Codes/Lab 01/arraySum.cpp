#include <iostream>
using namespace std;

int main(){
    int n;
    int sum=0;
    cout<<"Enter size of array ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter "<<n<<" elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    cout<<"Summation of array values is: "<<sum<<endl;
    return 0;
}
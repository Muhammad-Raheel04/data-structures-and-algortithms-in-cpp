#include <iostream>
using namespace std;

int main()
{
    int arr[5], *p;
    p = arr;
    cout << "Enter 5 numbers " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> *(p + i);
    }
    int maxNum=arr[0];
    for (int i = 1; i < 5; i++)
    if(maxNum<(*(p+i))){
        maxNum=*(p+i);
    }
    cout<< "Max Array Element "<<maxNum;
}
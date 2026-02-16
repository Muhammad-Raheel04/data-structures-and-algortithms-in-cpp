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
    cout << "Array elements ";
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << " ";
    }
}
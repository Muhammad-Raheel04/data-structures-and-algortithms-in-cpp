#include <iostream>
using namespace std;

void traverse(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insert(int arr[], int &n, int pos, int item)
{
    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = item;
    n++;
    cout << "Element inserted successfully.\n";
}
void deleteElement(int arr[], int &n, int pos)
{
    if (pos < 1 || pos > n)
    {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully.\n";
}
int linearSearch(int arr[], int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int n, int item)
{
    int beg = 0, end = n - 1, mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == item)
        {
            return mid;
        }
        else if (item < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    return -1;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}
int main()
{
    int n = 0, choice;
    int arr[100];
    do
    {
        cout << "\n\n===== MAIN MENU =====\n";
        cout << "1. Traverse the Array\n";
        cout << "2. Insert Data into an Array\n";
        cout << "3. Delete from an Array\n";
        cout << "4. Linear Search on an Array\n";
        cout << "5. Sort the Array\n";
        cout << "6. Binary Search on an Array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            traverse(arr, n);
            break;

        case 2:
        {
            int item, pos;
            cout << "Enter element to insert: ";
            cin >> item;
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;
            insert(arr, n, pos, item);
            break;
        }

        case 3:
        {
            int pos;
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;
            deleteElement(arr, n, pos);
            break;
        }

        case 4:
        {
            int item, loc;
            cout << "Enter element to search (Linear Search): ";
            cin >> item;
            loc = linearSearch(arr, n, item);
            if (loc != -1)
                cout << "Element found at position " << loc + 1 << endl;
            else
                cout << "Element not found\n";
            break;
        }

        case 5:
        {
            int sortChoice;
            cout << "Sort Menu:\n1. Bubble Sort\n2. Selection Sort\nChoose: ";
            cin >> sortChoice;
            if (sortChoice == 1)
                bubbleSort(arr, n);
            else if (sortChoice == 2)
                selectionSort(arr, n);
            else
                cout << "Invalid choice!\n";
            cout << "Array sorted successfully!\n";
            break;
        }

        case 6:
        {
            int item, loc;
            cout << "Enter element to search (Binary Search): ";
            cin >> item;
            loc = binarySearch(arr, n, item);
            if (loc != -1)
                cout << "Element found at position " << loc + 1 << endl;
            else
                cout << "Element not found\n";
            break;
        }

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
    return 0;
}
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = NULL;
void createList(){
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = NULL;

    head = first;

    cout << "List Created Successfully!\n";
}
void traverse(){
    if(head == NULL){
        cout << "List is empty!\n";
        return;
    }

    Node *current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertFirst(int item){
    Node *newNode = new Node;

    if(newNode == NULL){
        cout << "Memory Overflow!\n";
        return;
    }

    newNode->data = item;
    newNode->next = head;
    head = newNode;

    cout << "Inserted at beginning successfully!\n";
}

void insertAfter(int key, int item){

    Node *current = head;

    while(current != NULL && current->data != key){
        current = current->next;
    }

    if(current == NULL){
        cout << "Node not found!\n";
        return;
    }

    Node *newNode = new Node;

    newNode->data = item;
    newNode->next = current->next;
    current->next = newNode;

    cout << "Inserted after " << key << " successfully!\n";
}

void insertSorted(int item){

    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;

    if(head == NULL || head->data >= item){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;

    while(current->next != NULL && current->next->data < item){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    cout << "Inserted in sorted order successfully!\n";
}

int main(){

    int choice, value, key;
    do{
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Create List\n";
        cout << "2. Traverse List\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert After Given Node\n";
        cout << "5. Insert in Sorted List\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                createList();
                break;

            case 2:
                traverse();
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertFirst(value);
                break;

            case 4:
                cout << "Enter node value after which to insert: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(key, value);
                break;

            case 5:
                cout << "Enter value: ";
                cin >> value;
                insertSorted(value);
                break;

            case 6:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    }while(choice != 6);
    return 0;
}
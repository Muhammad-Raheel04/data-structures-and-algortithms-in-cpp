#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// 1. Create Linked List
void createList() {
    int n, value;
    cout << "How many nodes? ";
    cin >> n;

    for(int i=0;i<n;i++) {
        Node* newNode = new Node();
        cout << "Enter value: ";
        cin >> value;
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// 2. Traverse Linked List
void traverseList() {
    Node* temp = head;

    if(temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 3. Insert at Beginning
void insertBeginning() {
    Node* newNode = new Node();
    cout << "Enter value: ";
    cin >> newNode->data;

    newNode->next = head;
    head = newNode;
}

// 4. Insert After Given Node
void insertAfter() {
    int key, value;
    cout << "Enter node value after which you want to insert: ";
    cin >> key;

    Node* temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node();
    cout << "Enter value: ";
    cin >> value;

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Insert in Sorted List
void insertSorted() {
    Node* newNode = new Node();
    cout << "Enter value: ";
    cin >> newNode->data;

    if(head == NULL || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data < newNode->data)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// 6. Delete First Node
void deleteFirst() {
    if(head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// 7. Delete Node After Given Node
void deleteAfter() {
    int key;
    cout << "Enter node value: ";
    cin >> key;

    Node* temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        cout << "Deletion not possible\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// 8. Delete Node with Given Value
void deleteValue() {
    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    if(head == NULL) return;

    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if(temp->next == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// 9. Search Unsorted List
void searchUnsorted() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == value) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Not Found\n";
}

// 10. Search Sorted List
void searchSorted() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node* temp = head;

    while(temp != NULL && temp->data <= value) {
        if(temp->data == value) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Not Found\n";
}

int main() {

    int choice;

    while(true) {

        cout << "\nMAIN MENU\n";
        cout << "PRESS 1 FOR CREATING A LINKED LIST\n";
        cout << "PRESS 2 FOR TRAVERSING THE LINKED LIST\n";
        cout << "PRESS 3 FOR INSERTING DATA AT THE BEGINNING\n";
        cout << "PRESS 4 FOR INSERTING DATA AFTER A GIVEN NODE\n";
        cout << "PRESS 5 FOR INSERTING DATA INTO A SORTED LIST\n";
        cout << "PRESS 6 FOR DELETING THE FIRST NODE\n";
        cout << "PRESS 7 FOR DELETING THE NODE AFTER A GIVEN NODE\n";
        cout << "PRESS 8 FOR DELETING NODE WITH GIVEN VALUE\n";
        cout << "PRESS 9 FOR SEARCHING IN UNSORTED LIST\n";
        cout << "PRESS 10 FOR SEARCHING IN SORTED LIST\n";
        cout << "PRESS 0 TO EXIT\n";

        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch(choice) {

            case 1: createList(); break;
            case 2: traverseList(); break;
            case 3: insertBeginning(); break;
            case 4: insertAfter(); break;
            case 5: insertSorted(); break;
            case 6: deleteFirst(); break;
            case 7: deleteAfter(); break;
            case 8: deleteValue(); break;
            case 9: searchUnsorted(); break;
            case 10: searchSorted(); break;
            case 0: return 0;
            default: cout << "Invalid Choice\n";

        }
    }

    return 0;
}
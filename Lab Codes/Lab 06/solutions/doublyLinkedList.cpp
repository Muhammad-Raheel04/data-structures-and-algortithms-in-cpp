#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void traverseForward() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void traverseBackward() {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

void search(int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

void deleteNode(int key) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Not Found\n";
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        delete temp;
        return;
    }

    if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    traverseForward();
    traverseBackward();

    search(20);

    deleteNode(20);

    traverseForward();

    return 0;
}
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
int main(){
    // Create Three Nodes
    Node* head= nullptr;
    Node* first=new Node();
    Node* second=new Node();
    
    // Assign data and next points
    first->data=20;
    first->next=second;

    second->data=30;
    second->next=nullptr;

    head=first; // head just points to first node

    // Traverse and print list
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}
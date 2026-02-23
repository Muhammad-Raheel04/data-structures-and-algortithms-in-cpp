#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
 Node *head=NULL;
void insertFirst(int item){
    Node *newNode=new Node;

    if(newNode==NULL){
        cout<<"Memory Overflow!\n";
        return;
    }
    newNode->data=item;
    newNode->next=head;
    head=newNode;
}
void createList(){
  // Create Three Nodes
    Node *first=new Node;
    Node *second=new Node;
    Node *third=new Node;
    
    // Assign data and next points
    first->data=20;
    first->next=second;

    second->data=30;
    second->next=third;

    third->data=40;
    third->next=nullptr;

    head=first; // head just points to first node
}
void traverse(){
    Node *current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
}
int main(){
    createList();
    cout<<"Original List"<<endl;
    traverse();
    insertFirst(5);
    cout<<endl;
    cout<<"After inserting at beginning: "<<endl;
    traverse();
    return 0;
}
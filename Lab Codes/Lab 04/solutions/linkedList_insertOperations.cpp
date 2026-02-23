#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
 Node *head=nullptr;
void createList(){
    Node *first=new Node;
    Node *second=new Node;
    Node *third=new Node;

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;
    
    head=first;
}
void traverse(){
    Node *current=head;
    while(current!=nullptr){
        cout<<current->data<<endl;
        current=current->next;
    }
    cout<<endl;
}
void insertFirst(int item){
    Node *newNode=new Node;
    if(newNode==nullptr){
        cout<<"Memory Overflow!\n";
        return;
    }
    newNode->data=item;
    newNode->next=head;
    head=newNode;
}
void insertAfter(Node *loc,int item){
    if(loc==nullptr){
        cout<<"Given node is NULL. Cannot insert after it.\n";
        return;
    }
    Node *newNode=new Node;
    if(newNode==nullptr){
        cout<<"Memory Overflow\n";
        return;
    }
    newNode->data=item;
    newNode->next=loc->next;
    loc->next=newNode;
}
int main(){
    createList();
    cout<<"Original List: "<<endl;
    traverse();

    insertFirst(11);
    cout<<"Afte inserting 11 at beginning"<<endl;
    traverse();

    insertAfter(head->next,25); // insert 25 after second node
    cout<<"After inserting 25 after second node"<<endl;
    traverse();
    return 0;
}
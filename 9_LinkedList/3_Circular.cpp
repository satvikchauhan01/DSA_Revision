#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
    Node(int val, Node* x){
        data=val;
        next=x;
    }
};
void insertAtEnd(Node* &head, int val){
    Node* newNode= new Node(val);
    if(head==NULL){head=newNode;newNode->next=head;return;}
    
    Node* temp=head;
    while(temp->next!=head){ //iterrate to the last element
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
}
void insertAtHead(Node* &head, int val){
    Node* newNode= new Node(val);
    if(head==NULL){
        head=newNode;
        head->next=head;
        return;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    head=newNode;
}
void insertAtN(Node* &head, int val, int k){
    if(k==1){insertAtHead(head, val); return;}
    Node* newNode= new Node(val);

    Node* temp=head;
    while(k>2){
        temp=temp->next;
        k--;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void print(Node* head){
    if(head==NULL){cout<<"NULL";return;}
    Node* temp=head;
    cout<<temp->data<<" -> ";
        temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<head->data<<"(head)"<<endl;;
}
int main() {
    Node* head=NULL;
    for(int i=14; i<40; i+=5){
        insertAtEnd(head,i);
    }
    print(head);
    insertAtHead(head,12);
    print(head);

    insertAtN(head,21,8);
    print(head);
}
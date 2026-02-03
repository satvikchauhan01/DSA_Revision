#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * next;   //next pointer is of type Node so it will only point to any node no other
    
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
    if(head==NULL){head=newNode; return;}

    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void insertAtHead(Node* &head,int val){
    Node* newNode= new Node(val);
    if(head==NULL){head=newNode; return;}

    newNode->next=head;
    head=newNode;
}
void insertAtk(Node* &head, int val, int k){
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
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main() {
   Node* head=NULL;
   for(int i=0; i<5; i++){
    insertAtEnd(head, i+11);
   }
   print(head);

   insertAtHead(head,21); 
   print(head);

   insertAtk(head,33,1);
   print(head);
}
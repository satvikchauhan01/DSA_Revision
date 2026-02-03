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
//DELETION://
void deleteFromEnd(Node* &head){
    if(head==NULL){return;}
    if(head->next==NULL){
        Node* del=head;
        head=NULL;
        delete del;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return;

}

void deleteHead(Node * &head){
    if(head==NULL){return;}
    if(head->next==NULL){
        Node* del=head;
        head=NULL;
        delete del;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
void deleteAtN(Node* &head, int n){
    if(head==NULL){return;}
    if(head->next==NULL){
        Node* del=head;
        head=NULL;
        delete del;
        return;
    }
    if(n==1){deleteHead(head);return;}
    
    if(n==2){Node* ok=head->next; 
        head->next=head->next->next; 
        delete ok;
        return; 
    }

    Node* temp=head;
    while(n>2){
        temp=temp->next;
        n--;
    }
    Node *del=temp->next;
    temp->next=temp->next->next;
    delete del;
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

   deleteFromEnd(head);
   print(head);

   deleteHead(head);
   print(head);

   deleteAtN(head,5);
   print(head);
}
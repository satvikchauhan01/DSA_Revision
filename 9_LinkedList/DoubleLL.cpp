//why not used: 1. more space due to double pointers
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtEnd(Node* &head, int val){
    Node* newNode=new Node(val);
    if(head==NULL){head=newNode; return;}
    Node* temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAtHead(Node* &head, int val){
    Node* newNode= new Node(val);
    if(head==NULL){head=newNode; return;}
    newNode->next=head;
    head->prev=newNode;
    head=head->prev;
}
void insertAtN(Node* &head, int val, int n){
   
    if(n==1){insertAtHead(head,val); return;}
     Node* newNode=new Node(val);

     Node* temp=head;
     while(n>1){
        temp=temp->next;
        n--;
     }
     temp->prev->next=newNode;
     newNode->prev=temp->prev;

     temp->prev=newNode;
     newNode->next=temp;
     
     
}
void print(Node* head){
    Node* temp=head;
    cout<<"NULL <- ";
    while(temp!=NULL){
        cout<< temp->data<<" <=> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main() {
    Node* head=NULL;
    for(int i=12; i<18; i++){
        insertAtEnd(head,i);
    }
    print(head);

    insertAtHead(head,11);
    print(head);

    insertAtN(head,10,1);
    print(head);

}
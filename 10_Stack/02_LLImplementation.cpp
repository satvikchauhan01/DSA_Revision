#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
class Stack{
    public:
    Node* top;
    Stack(){
        top=NULL;
    }

    void push(int n){
        Node* newNode=new Node(n);
        newNode->next=top;
        top=newNode;
    }
    void pop(){
        if(top==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    int peek(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->val;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
};
int main() {
    Stack st;
    for(int i=1; i<=5; i++){
        st.push(5);
    }
    cout<<st.isEmpty()<<endl;
    cout<<st.peek()<<endl;
}
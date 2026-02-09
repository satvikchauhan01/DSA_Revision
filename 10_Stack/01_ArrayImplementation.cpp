#include <bits/stdc++.h>
using namespace std;
class Mystack{
    public:
    int *arr;
    int top;
    int size;
    Mystack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){cout<<"No element in stack"<<endl; return -1;}
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1){return true;}
        return false;
    }

};
int main() {
    Mystack st(5);
    for(int i=1; i<=5; i++){
        st.push(5);
    }
    cout<<st.isEmpty()<<endl;
    st.push(6);
    cout<<st.top;
}
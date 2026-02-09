#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void push(int val){
        if(rear==size-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear]=val;
    }
    void pop(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front++;
    }
    int peekFront(){
        if(front==-1){
            cout<<"No element in queue"<<endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
Queue q(5);
    
}
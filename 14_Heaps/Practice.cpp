#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
void bubbleUp(int index){
    int i=index;
    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent] < heap[i]){
            swap(heap[parent], heap[i]);
            i=parent;
        }
        else{
            break;
        }
    }
}

void bubbledown(){
    int i=0;
    int n=heap.size();
    while(i<heap.size()){
        int current=i;
        int left=2*i+1;
        int right=2*i+2;
        if(heap[left] >heap[current] && left<n){
            current=left;
        }
        if(heap[right]> heap[current] && right<n){
            current=right;
        }
        if(current !=i){
            swap(heap[current], heap[i]);
            i=current;
        }
        else{
            break;
        }
    }

}
void insert(int val){
    heap.push_back(val);
    int size=heap.size()-1;
    bubbleUp(size);
}

void delete1(){
    if(heap.size()==0){
        cout<<"HEap is empty";
        return;
    }
    heap[0]=heap.back();
    heap.pop_back();
    bubbledown();
}

int main(){
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    for(int i=0 ; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;

    delete1();
    for(int i=0 ; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;

    
}
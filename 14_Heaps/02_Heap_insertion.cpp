#include <bits/stdc++.h>
using namespace std;
class MaxHeap{
    public: 
    vector<int> heap;
    void bubbleUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent] < heap[index]){
                swap(heap[parent], heap[index]);
                index=parent;
            }
            else{
                break;
            }
        }
    }
    void insert(int val){
        heap.push_back(val);
        int n=heap.size()-1;
        bubbleUp(n);
    }
};
int main(){
    MaxHeap h;
    h.insert(10);
    h.insert(20); 
    h.insert(5);
    h.insert(15);   
    for(int i=0; i<h.heap.size(); i++){
        cout<<h.heap[i]<<" ";
    }
}
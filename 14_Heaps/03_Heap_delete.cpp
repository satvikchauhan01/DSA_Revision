#include <bits/stdc++.h>
using namespace std;    
 //time complexity of delete operation in a max heap is O(log n) 
    //where n is the number of elements in the heap. 
    //This is because after deleting the root node, 
    //we need to maintain the max heap property by performing a "bubble down" operation, 
    //which takes O(log n) time in the worst case.
    
class MaxHeap{
    public:
    vector<int> heap;
    void bubbleDown(){   //function to maintain the max heap property after deletion
        int i=0;
        int n=heap.size();
        
        while(i < n){
            int left=2*i+1;
            int right=2*i+2;
            int largest=i;

            if(heap[left] > heap[largest] && left<n){
                largest=left;
            }
            if(heap[right] > heap[largest] && right<n){
                largest=right;
            }
            if(largest!=i){
                swap(heap[i], heap[largest]);
                i=largest;
            }else{
                break;
            }
        }
    }
    void deleteRoot(){  //deleteion occurs only at the root node in a max heap
        if(heap.empty()){
            cout<<"Heap is empty!"<<endl;
            return;
        }
        heap[0]=heap.back();
        heap.pop_back();
        bubbleDown();
    }


};
int main(){
    MaxHeap h;
    h.heap={20, 15, 10, 5};
    h.deleteRoot();
    for(int i=0; i<h.heap.size(); i++){
        cout<<h.heap[i]<<" ";
    }
}
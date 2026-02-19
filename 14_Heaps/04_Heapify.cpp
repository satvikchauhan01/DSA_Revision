#include <bits/stdc++.h>
using namespace std;    
class MaxHeap{
    public:
    void heapify(vector<int> &arr, int size, int index){   //function to maintain the max heap property after insertion
        int i=index;
        int n=size;

        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[left]> arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]> arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);         //in this step we used to do i= largest(which wa s passed in the next while iteration)  but here w e pass it directly in the place of i in the heapify function as a recursive call
        }
    }
    void build(vector<int> & arr, int n){
    for(int i=(n/2)-1 ; i>=0; i--){
        heapify(arr, n ,i);
    }
}

};

int main(){
    MaxHeap h;
    vector<int> arr={10,3,5,30,2,8,15};
    int n=arr.size();
    h.build(arr, n);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
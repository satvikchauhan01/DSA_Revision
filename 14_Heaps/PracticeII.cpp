#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i ){
    int current=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[current] < arr[left]){
        current=left;
    }
    if(right<n && arr[right] >arr[current]){
        current =right;
    }
    if(current!=i){
        swap(arr[current], arr[i]);
        heapify(arr, n, current);
    }
}
int main(){
    vector<int> arr={10,3,5,30,2,8,15};
    int n=arr.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
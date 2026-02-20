#include <bits/stdc++.h>    
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int j=0;
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                arr[j++]=pq.top();
                pq.pop();
            }
            
        }
        while(!pq.empty()){
            arr[j++]=pq.top();
            pq.pop();
        }
        
    }
};
int main(){
    Solution s;
    vector<int> arr = {6,5,3,2,8,10,9};
    int k = 3;
    s.nearlySorted(arr,k);
    for(int i: arr){
        cout<<i<<" ";
    }
}
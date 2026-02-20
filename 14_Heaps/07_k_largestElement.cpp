#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: arr){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            result.push_back(a);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,2,1,5,6,4};
    int k = 4;
    vector<int> result = s.kLargest(arr,k);
    for(int i: result){
        cout<<i<<" ";
    }
}
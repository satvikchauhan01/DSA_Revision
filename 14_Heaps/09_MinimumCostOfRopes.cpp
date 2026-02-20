#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size()==1)return 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        int Finalcost=0;
        
        for(int i: arr){
            pq.push(i);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            
            int sum=a+b;
            Finalcost+=sum;
            pq.push(sum);
        }
        return Finalcost;
    }
};

int main(){
    Solution s;
    vector<int> arr = {4, 3, 2, 6};
    cout<<s.minCost(arr);
}
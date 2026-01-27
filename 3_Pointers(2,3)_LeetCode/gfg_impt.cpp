#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
      
        int n =arr.size();
        int pivot=0;
        //find the pivot element 
        while(pivot<n-1){
            if(arr[pivot]>arr[pivot+1]){
                break;
            }
            pivot++;
        }
        int low=(pivot+1)%n;  //edge case: if array is completely sorted
        int high=pivot;
        
        //now implement 2 sum approacgh with circular conditions
        while(low!=high){
            int sum=arr[low]+arr[high];
            if(sum==target)return true;
            else if(sum<target){
                low=(low+1)%n;
            }
            else{
                high= (high+n-1)%n;
            }
        }
        return false;
        
    }
};
int main() {
    vector<int> arr={5,7,10,1,3,4};
    Solution s;
    cout<<s.pairInSortedRotated(arr,2);
}
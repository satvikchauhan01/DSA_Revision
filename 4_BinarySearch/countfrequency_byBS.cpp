#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
        int n=nums.size();
        int l=0, r=n-1;
        int first=-1, last=-1;
        int count =0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                first=mid;
                last=mid;
                count++;
                while(first-1>=0 && nums[first-1]==target){
                    first--;
                    count++;
                }
                while(last+1<n && nums[last+1]==target){
                    last++;
                    count++;
                }
              return count;  
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector <int> arr={12,34,56,76,76,76,100};
    cout<<"Frequency: "<<s.countFreq(arr,76);

    
}
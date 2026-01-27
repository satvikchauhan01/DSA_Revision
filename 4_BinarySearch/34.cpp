//first and last occurences

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n-1;
        int first=-1, last=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                first=mid;
                last=mid;
                while(first-1>=0 && nums[first-1]==target){
                    first--;
                }
                while(last+1<n && nums[last+1]==target){
                    last++;
                }
                return {first, last};
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return{first, last};
    }
};
int main() {
Solution s;
    vector <int> arr={12,34,56,76,76,76,100};
    vector <int> ans=s.searchRange(arr,76);
    for(int i=0; i<2; i++){
        cout<<ans[i]<<" ";
    }
}
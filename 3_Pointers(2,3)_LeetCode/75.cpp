#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low++],nums[mid++]);
            }
            else if(nums[mid]==2){
                swap(nums[high], nums[mid]);
                high--;
            }
            else{
                mid++;
            }
        }
    }
};
int main() {
    Solution s;
    vector <int> arr={0,1,2,1,1,0,2,0,1,1,0,2,1,0};
    s.sortColors(arr);
    for(int i=0; i<arr.size()-1; i++){
        cout<<arr[i]<<" ";
    }
}

//Simply think like 
// if 0 move to front and increase low and mid 
// if 1 do nothing only increase the mid 
// if 2 move to back and decrease high 
// dont increase mid in third case
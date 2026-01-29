#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int k=0;   //k is window size or the maximum number of 1s in array
        for(int i=0; i<n; i++){                  //O(n)
            k+=nums[i];
        }
        if(k==0 || k==n){return 0;}
        int ones=0;     //ones is the number o ones in each window


        for(int i=0; i<k; i++){                   //O(k) worst case k==n
            ones=ones+nums[i%n];
        }//here we calculated the number of ones in first window
        
        int maxOnes=ones;            
        for(int i=k; i<n+k; i++){              //O(n) anytime it runs from k to n+k so runs n times
            ones= ones - nums[(i-k)%n]+ nums[i%n];   
            maxOnes=max(ones,maxOnes);
        }
        return k-maxOnes;

    }
};
int main() {
    Solution s;
    vector<int> arr={0,1,1,1,0,0,1,1,0};
    cout<<s.minSwaps(arr);
    
}
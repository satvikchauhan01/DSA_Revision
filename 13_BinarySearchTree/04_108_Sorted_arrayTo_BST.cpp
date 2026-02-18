#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:   int val;  
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    TreeNode* build(vector<int> &nums, int l, int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* node= new TreeNode(nums[mid]);
        node->left =build(nums, l, mid-1);
        node->right= build(nums, mid+1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};

int main(){
    vector<int> nums={-10,-3,0,5,9};
    Solution s;
    TreeNode* ans=s.sortedArrayToBST(nums);
    cout<<ans->val;
}
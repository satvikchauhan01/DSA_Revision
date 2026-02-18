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
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root==NULL)return 0;
        if(root->val>=low && root->val<=high){
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else if(root->val <low){
            return rangeSumBST(root->right, low, high);
        }
        else{
            return rangeSumBST(root->left, low, high);
        }

    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    Solution s;
    int ans=s.rangeSumBST(root, 7, 15);
    cout<<ans;
}
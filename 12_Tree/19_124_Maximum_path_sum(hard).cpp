/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public: 

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};
class Solution {
public:
    int maxi=INT_MIN;
    int height(TreeNode* root){
        if(!root)return 0;
        int ls=max(0,height(root->left));
        int rs=max(0,height(root->right));
        maxi=max(maxi, ls+rs+root->val);

        return root->val+ max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return maxi;
    }
};
int main() {
    Solution s;
    TreeNode* root=new TreeNode(-10);
    root->left=new TreeNode(9);   
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<s.maxPathSum(root);
    return 0;
}
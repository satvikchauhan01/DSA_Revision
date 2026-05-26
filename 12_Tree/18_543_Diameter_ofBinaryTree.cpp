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
    int maxi=0;
    int height(TreeNode* root) {
        if(root==NULL){return 0;} // we return the zero because for the leaf nodes when the null values return 0 the height of that node is 1 (draw the diagram)
        int lh=height(root->left);
        int rh=height(root->right);
        maxi=max(maxi, lh+rh);
        return 1+ max(rh,lh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){return 0;}
        height(root);
        return maxi;
    }
};
int main() {
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);   
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<s.diameterOfBinaryTree(root);
    return 0;
}
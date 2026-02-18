#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int lh = height(root->left);
        if(lh == -1) return -1;

        int rh = height(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    cout << boolalpha << Solution().isBalanced(root) << endl; // Output: true
    return 0;
}
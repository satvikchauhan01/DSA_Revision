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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){return NULL;}
    
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    inorder(root);cout<<endl;
    Solution s;
    TreeNode* newRoot=s.invertTree(root);  
    inorder(newRoot);
}
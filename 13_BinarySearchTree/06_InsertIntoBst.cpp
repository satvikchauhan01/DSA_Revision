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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* newNode=new TreeNode(val);
            return newNode;
        }
        if(val < root->val){
            root->left=insertIntoBST(root->left, val);
        }
        else{
            root-> right= insertIntoBST(root->right, val);
        }
        return root;
    }
};
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution s;
    TreeNode* ans=s.insertIntoBST(root, 5);
    cout<<ans->right->val;
}
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){return NULL;}
        if(root->val==val){return root;}

        if(val<root->val){
            return searchBST(root->left, val);
        }
        else{
            return searchBST(root->right, val);
        }
          
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution s;
    TreeNode* ans=s.searchBST(root, 2);
    if(ans!=NULL){
        cout<<ans->val;
    }
    else{
        cout<<"Value not found in the BST";
    }
}
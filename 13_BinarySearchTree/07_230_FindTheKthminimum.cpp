#include <iostream>
#include <vector>
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
    void inorder(TreeNode* root, vector<int> &ret){
        if(root==NULL){return ;}
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        if(root==NULL){return 0;}
        inorder(root, ret);
        return ret[k-1];
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution s;
    int ans=s.kthSmallest(root, 1);
    cout<<ans;
}
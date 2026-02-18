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
    void inorder(TreeNode* root, vector<int> & ret){
        if(root==NULL){return;}
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ret;
        inorder(root,ret);
        int l=0;
        int r=ret.size()-1;
        while(l<r){
            int sum=ret[l] + ret[r];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                r--;
            }
            else{l++;}
        }
        return false;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    Solution s;
    bool ans=s.findTarget(root, 9);
    cout<<boolalpha<<ans;
}
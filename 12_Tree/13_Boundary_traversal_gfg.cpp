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
    void left(TreeNode* root, vector<int> &ret){
        if(root==NULL || (root->left==NULL && root->right==NULL)){return;}
        
        ret.push_back(root->val);
        if(root->left){
            left(root->left, ret);
            
        }
        else{
            left(root->right, ret);
        }
    }
    void right(TreeNode* root, vector<int> &ret){
        if(root==NULL || (root->left==NULL && root->right==NULL)){return;}
        
        if(root->right){
            right(root->right, ret);
        }
        else{
            right(root->left, ret);
        }
        ret.push_back(root->val);
    }
    void leaf(TreeNode * root, vector<int> &ret){
        if(root==NULL){return;}
        
        if(root->left==NULL && root->right==NULL){
            ret.push_back(root->val);
            return;
            
        }
        leaf(root->left, ret);
        leaf(root->right, ret);
    }
    
    vector<int> boundaryTraversal(TreeNode *root) {
    vector<int> ret;
    if(root == NULL) return ret;

    ret.push_back(root->val);

    left(root->left, ret);
    leaf(root->left, ret);
    leaf(root->right, ret);
    right(root->right, ret);

    return ret;
}

};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> result = Solution().boundaryTraversal(root);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}
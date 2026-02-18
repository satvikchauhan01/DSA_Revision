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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){return {};}
        queue <TreeNode*> q;
        q.push(root);
        vector<int> ret;
        while(!q.empty()){
            int ls= q.size();
            int toPush;
            for(int i=0; i<ls; i++){
                TreeNode* front=q.front();
                q.pop();
                toPush=front->val;

                if(front->left){q.push(front->left);}
                if(front->right){q.push(front->right);}
            }
            ret.push_back(toPush);
        }
        return ret;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    Solution s;
    vector<int> result = s.rightSideView(root); 
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Base Conditions: 
        vector<vector<int>> ret;
        if(root==NULL){return ret;}                                 //  if the tree is empty, return an empty vector
        if(root->left==NULL && root->right==NULL)return{{root->val}};       //if there is only one node in the tree, return a vector containing that node's value
        
        //declaring and initializing queue
        queue <TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize=q.size();                     //get the size of the queue at the start of each level, this will help us to know how many nodes are there in the current level
            vector<int> level;           

            for(int i=0; i<levelSize; i++){
                TreeNode* front=q.front();                                    //get the front node of the queue and pop it
                q.pop();
                level.push_back(front->val);                                    //push the value of the front node into the level vector

                if(front->left){q.push(front->left);}                //check if left and right child exist or not before pushing into queue
                if(front->right){q.push(front->right);}
            }
            ret.push_back(level);
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
    vector<vector<int>> result = s.levelOrder(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}
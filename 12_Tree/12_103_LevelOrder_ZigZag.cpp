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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //Base Conditions: 
        vector<vector<int>> ret;
        if(root==NULL){return ret;}
        if(root->left==NULL && root->right==NULL)return{{root->val}};
        
        //declaring and initializing queue
        queue <TreeNode *> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int levelSize=q.size();
            vector<int> level;
            
            for(int i=0; i<levelSize; i++){
                TreeNode* front=q.front();
                q.pop();
                level.push_back(front->val);

                if(front->left){q.push(front->left);}
                if(front->right){q.push(front->right);}
            }
            if(flag){
                reverse(level.begin(), level.end());
                flag=false;
            }
            else{
                flag=true;
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
    vector<vector<int>> result = Solution().zigzagLevelOrder(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
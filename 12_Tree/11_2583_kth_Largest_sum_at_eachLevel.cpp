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

long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL){return -1;}
        queue <TreeNode*> q;
        q.push(root);
        vector<long long> ret;

        while(!q.empty()){
            int ls= q.size();
            long long sum=0;
            for(int i=0; i<ls; i++){
                TreeNode* front=q.front();
                q.pop();
                sum+=front->val;

                if(front->left){q.push(front->left);}
                if(front->right){q.push(front->right);}
            }
            ret.push_back(sum);    
        }
        sort(ret.begin(), ret.end());
        if(k>ret.size()){return -1;}
        return ret[ret.size()-k];
    }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    
    cout << kthLargestLevelSum(root, 1) << endl; // Output: 10 (sum of level 1)
    cout << kthLargestLevelSum(root, 2) << endl; // Output: 5 (sum of level 2)
    return 0;
}
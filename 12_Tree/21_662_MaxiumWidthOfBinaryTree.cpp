/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int width=0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int n=q.size();
            long long min=q.front().second;
            int first=0, last=0;
            for(int i=0; i<n; i++){
                  // now we will fetch the current node and its relattive index
                long long currIndex = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();

                // Update the first index if it's the first node 
                if (i == 0){first = currIndex;}

                // Update the last index if it's the last node
                if (i == n - 1){last = currIndex;}

                // If left child exists, push it with calculated index
                if (node->left) q.push({node->left, 2 * currIndex + 1});

                // If right child exists, push it with calculated index
                if (node->right) q.push({node->right, 2 * currIndex + 2});
            }

            width = max(width, last - first + 1);
        }
        return width;
    }
};
int main() {
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);   
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(5);
    cout<<s.widthOfBinaryTree(root);
    return 0;
}
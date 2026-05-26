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
    bool same(TreeNode* p, TreeNode* q){
        if(!p && !q){return true;}
        if(!p || !q){return false;}
        if(p->val != q->val){
            return false;
        }
        return same(p->left, q->right) && same(p->right,q->left);

    }
    bool isSymmetric(TreeNode* root) {
        return same(root->left, root->right);
        }
};
int main() {
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);   
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout<<s.isSymmetric(root);
    return 0;
}
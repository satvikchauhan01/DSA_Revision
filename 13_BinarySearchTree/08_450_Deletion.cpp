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

/*
 Step 1: find the node to be deleted by comparisons
 Step2: restructure the children whilwe preserving the BST property:
    Case1: No Children(leaf Node) ->delet the required node directly
    case2: One child   -> replace the current node with its current child and delet the node;
    Case3: 2 child     ->to maintain BST order we can either choose inorder succesor(smalles in RST)
           inorderpredeccsor(largest in LST) and replace it with current node;
*/
             
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* node){
        //find the min element from the right sub tree
        while(node->left!=NULL){
            node=node->left;
        }
        return node;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){return NULL;}
        
        //search: 
        if(key<root->val){
            root->left=deleteNode(root->left, key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right, key);
        }
        else{ 
            //case :leaf is handled in both of these as if both are null then either one is replaced with null
            //Case1: if no left child : replace the node with its right child
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //case 2: if no right child: replace the node with its left child
            else if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            //case 3: node has 2 children:
            else{
                //find inorder successor from RST
                TreeNode* temp=inorderSuccessor(root->right);
                //copy the min element value in the node which we were supposed to delete
                root->val=temp->val;
                //now we need to delete that elemnt with which we exchanged
                root->right= deleteNode(root->right, temp->val);
            }
        }
        return root;
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
    TreeNode* ans=s.deleteNode(root, 3);
    cout<<ans->left->val;
}
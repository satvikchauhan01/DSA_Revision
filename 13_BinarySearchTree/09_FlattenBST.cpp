#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution {
  public:
    void inorder(Node* root, Node* &temp){
        if(root==NULL){return;}
        inorder(root->left, temp);
        
        temp->right=root;
        temp=temp->right;
        temp->left=NULL;
        
        inorder(root->right, temp);
    }
    Node *flattenBST(Node *root) {
        Node* dum=new Node(-1);
        Node* temp=dum;
        inorder(root,temp);
        return dum->right;
    }
};

int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->right= new Node(4);

    Solution s;
    Node* ans=s.flattenBST(root);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->right;
    }
    return 0;
}
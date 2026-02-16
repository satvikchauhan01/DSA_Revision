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
int LeftLeavesSum(Node* root){
    if(root==NULL)return 0;
    if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
        return root->left->data+ LeftLeavesSum(root->right);
    }
    int ls= LeftLeavesSum(root->left);
    int rs= LeftLeavesSum(root->right);
    return ls+rs;
}
int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(5);
    root->left->right= new Node(4);
    cout<<LeftLeavesSum(root);
}
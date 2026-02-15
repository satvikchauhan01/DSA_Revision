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
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int CountNodes(Node* root){
    if(root==NULL) return 0;
    int x= CountNodes(root->left); 
    int y=CountNodes(root->right);
    return x+y+1;
}

int CountLeaf(Node * root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    int x= CountLeaf(root->left); 
    int y=CountLeaf(root->right);
    return x+y; 
}
int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->right= new Node(4);
    cout<<CountNodes(root)<<endl;;
    cout<<CountLeaf(root);
}
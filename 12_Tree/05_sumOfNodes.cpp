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
int sum(Node* root){
    if(root==NULL){return 0;}
    int ls=sum(root->left);
    int rs=sum(root->right);
    return ls+rs+root->data;
}
int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->right= new Node(4);
    cout<<sum(root);
}
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


class Solution {
public:
    bool isSameTree(Node* p, Node* q) {
        if(p==NULL && q==NULL){return true;}
        if(p==NULL || q==NULL){return false;}
        if(p->val!=q->val){return false;}
        
        return isSameTree(p->left, q->left)  && isSameTree(p->right, q->right);
    }
};


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(4);
}
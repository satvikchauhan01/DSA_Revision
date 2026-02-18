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
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        // Your code here
        vector<int> ret;
        if(root==NULL){return ret;}
        
        queue <Node*> q;
        int level=0;
        q.push(root);
        
        
        while(!q.empty()){
            int ls=q.size();
            if(level==k){
                for(int i=0; i<ls; i++){
                    Node* front=q.front();
                    q.pop();
                    ret.push_back(front->data);
                }
                break;
            }
            for(int i=0; i<ls; i++){
                Node* front=q.front();
                q.pop();
                if(front->left){q.push(front->left);}
                if(front->right){q.push(front->right);}
            }
            level++;
        }
        return ret;
    }
};

int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    
    Solution s;
    vector<int> ans=s.Kdistance(root, 2);
    for(int i: ans){
        cout<<i<<" ";
    }
}
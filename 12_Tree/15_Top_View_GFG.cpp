
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
    vector<int> topView(Node *root) {
        // code here
        vector<int> result;
        if(root==NULL){return result;}
        
        //create a map to store the first node whicle lokking from the top at each horizontal distance
        //key: horizontal distance (int)
        //value: node value
        map<int,int> mpp;
        
        //create a quueue to stor the pair of node and horizontal disatnce
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            //extract the front pair
            pair<Node* ,int> front=q.front();
            q.pop();
            Node* node=front.first;
            int hd=front.second;
            
            
            //check if the hd exist in the map or not
            if(mpp.find(hd) ==mpp.end()){
                mpp[hd]=node->data;
            }
            if(node->left){q.push(make_pair(node->left,hd-1));}
            if(node->right){q.push(make_pair(node->right, hd+1));}
        }
        for(auto it: mpp){
            result.push_back(it.second);
        }
        return result;
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
    vector<int> ans=s.topView(root);
    for(int i: ans){
        cout<<i<<" ";
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; //number of vertices
    int m; //number of edges
    cout<<"Enter the Number of Vertices: "; cin>>n;
    cout<<"Enter the Number of edges :   "; cin>>m;

    unordered_map<int, list<int>> adjList;

    for(int i=0; i<m; i++){
        int u,v;
        cout<<"Enter Pair: (u,v)";      //u and v are the vertices that are connected by an edge
        cin>>u>>v;

        adjList[u].push_back(v);            //we do this for both directed and undirected graph as in directed graph only one way possible
        adjList[v].push_back(u);          //we do this only for undirected graph as both way possible
    }
    cout<<"Adjacecny List: ";
    for(auto i: adjList){
        cout<<i.first<<": ";
        for(auto j: i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
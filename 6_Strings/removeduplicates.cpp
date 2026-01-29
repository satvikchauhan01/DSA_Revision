#include <bits/stdc++.h>
using namespace std;
//optimal solution with O(N) T.C and O(1) S.C.

string removedup(string &str){
    vector <bool> vis(256,false);
    string result="";
    for(char i: str){
        if(!vis[i]){
            result.push_back(i);
            vis[i]=true;
        }
    }
    return result;
}
int main() {
    string str="abababababab";
    cout<<removedup(str);
}
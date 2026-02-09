#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="satvik";
    stack <char> st;
    for(char ch: s){
        st.push(ch);
    }
    string result="";
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    cout<<s<<endl;
    cout<<result;
}
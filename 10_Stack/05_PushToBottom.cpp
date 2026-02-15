#include <bits/stdc++.h>
using namespace std;
void pushToBottom(stack<int> &st, int val){
    if(st.empty()){st.push(val); return;}
    int temp=st.top();
    st.pop();
    pushToBottom(st,val);
    st.push(temp);
}
int main() {
    stack<int> st;
    for(int i=1; i<=5; i++){
        st.push(i);
    }
    pushToBottom(st,6);
    while(!empty(st)){
        cout<<st.top()<<" ";
        st.pop();
    }
}
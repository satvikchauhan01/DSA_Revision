#include <bits/stdc++.h>
using namespace std;

int value(int a, int b, char c){
    if(c=='^'){
        return pow(a,b);
    }
    else if(c=='*'){return a*b;}
    else if(c=='/'){return a/b;}
    else if(c=='+'){return a+b;}
    else if(c=='-'){return a-b;}
    else{
        return 0;
    }
}
int prefixEval(string s){
    stack <int> st;
    int i=0;
    while(i<s.length()){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            int push1=value(a,b,s[i]);
            st.push(push1);
        }
        i++;
    }
    return st.top();
}
int main() {
 string s="423*+3-";
 cout<<prefixEval(s);
}
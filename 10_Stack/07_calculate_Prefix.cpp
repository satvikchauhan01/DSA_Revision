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
    int i=s.length()-1;
    while(i>=0){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            int push1=value(a,b,s[i]);
            st.push(push1);
        }
        i--;
    }
    return st.top();
}
int main() {
 string s="-+2*376";
 cout<<prefixEval(s);
}
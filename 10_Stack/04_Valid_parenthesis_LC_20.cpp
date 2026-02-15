#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char ch: s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()){return false;}
                
               if(ch==')' && st.top()=='('  || ch=='}' && st.top()=='{' || ch==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
int main() {
Solution s;
    
}
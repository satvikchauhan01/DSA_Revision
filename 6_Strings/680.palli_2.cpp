#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool help(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++; r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(s[l] == s[r]){l++; r--;}
            else{
                return help(s,l+1,r)  ||  help(s,l,r-1);
             }
        }
        return true;
    }
};
int main() {
Solution s;

    string si ="abca";
    cout<<s.validPalindrome(si);
}
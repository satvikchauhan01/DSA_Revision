#include <bits/stdc++.h>
using namespace std;

bool isPallindroe(string str){
    int l=0;
    int r=str.length()-1;
    while(l<r){
        if(str[l]!=str[r]){
            return false;
        }
        l++; r--;
    }
    return true;
}
int main() {
    string str="naman";
    cout<<isPallindroe(str);
}
#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string str){
    int l=0;
    int r=str.length()-1;
    while(l<r){
        while(l<r && !isalnum(str[l])){l++;}
        while(l<r && !isalnum(str[r])){r--;}
        if(tolower(str[l])  !=  tolower(str[r])){
            return false;
        }
        l++; r--;
    }
    return true;
}
int main() {
    string str="A man, a plan, a canal: Panama";
    cout<<ispalindrome(str);
}
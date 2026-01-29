#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> visited1(26,0);


        if(s.length() != t.length()){return false;}
        for(char i: s){
            visited1[i-'a']++;
        }
        for(char i: t){
            visited1[i-'a']--;
        }
        for(int i=0; i<26; i++){
            if(visited1[i]!= 0){
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    string si="satvik";
    string t="asvikt";
    cout<<s.isAnagram(si,t);
}
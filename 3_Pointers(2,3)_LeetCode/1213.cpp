#include <bits/stdc++.h>
using namespace std;
#include <vector>
class Solution {
  public:
    // Function to find common elements in three arrays.
    
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0, j=0, k=0;
        int n=arr1.size();
        int m=arr2.size();
        int o=arr3.size();
        
        vector <int> ret;
        while(i<n && j<m && k<o){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                if(ret.empty() || ret.back() != arr1[i]){
                    ret.push_back(arr1[i]);
                    
                }
                i++;
                j++;
                k++;
            }
            else if(arr1[i] <arr2[j]){
                i++;
            }
            else if(arr2[j] <arr3[k]){
                j++;
            }
            else{
                k++;
            }
        }
        return ret;
    }
};
int main() {
    vector<int> arr1={10,20,30,40,80, 100};
    vector<int> arr2={20,40,80,98};
    vector<int> arr3={3, 20,56,80,100};
    Solution s;
    vector <int> ans=s.commonElements(arr1,arr2,arr3);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
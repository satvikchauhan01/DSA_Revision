#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //brute force:
        // int i=0;
        // int j=0; int k=0;
        // if(m==0 && n==1){
        //     nums1[0]=nums2[0];
        //     return;
        // }
        // if(n==0){
        //     return;
        // }
        // while(i<=m){
        //     if(nums1[j]>nums2[k]){
        //         int temp=nums1[j];
        //         nums1[j]=nums2[k];
        //         nums1[j+1]=temp;
        //         j++;
        //         k++;
        //     }
        //     else{
        //         j++;
        //     }
        //     i++;
        // }
        // while(k<n){
        //     nums1[j++]=nums2[k++];
        // }

        //optimal: use the array from back:
        int i=m-1, k=m+n-1, j=n-1;

        while(j>=0){
            if(i>=0 && nums1[i]>=nums2[j]){
                nums1[k--]=nums1[i--];
                
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }

    }
};

int main(){
    vector<int> arr={1,2,3,0,0,0};
    vector <int> arr2={2,5,6};
    Solution s;
    s.merge(arr,3,arr2,3);
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
}
#include <bits/stdc++.h>
using namespace std;
//kooko eating bananas 
class Solution {
public:
    int maxi(vector<int> &piles){
        int maxa=INT_MIN;
        int n=piles.size();
        for(int i=0; i<n; i++){
            if(piles[i]>maxa){maxa=piles[i];}
        }
        return maxa;
    }
    long long maxhours(vector <int> &piles, int k){
        long long hours=0;
        for(int p: piles){
            hours=hours+ ((p+k-1)/k);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        long long  hours;
        int ans=0;
        int r=maxi(piles);
        while(l<=r){
            int mid=(l+r)/2;
            hours=maxhours(piles, mid);
            if(hours<=h){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};



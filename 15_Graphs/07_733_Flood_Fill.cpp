#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int r, int c , vector<vector<int>>& image, int originalColor, int newColor, int n, int m){
        if(r<0 || r>=n|| c<0 || c>=m)return;

        if(image[r][c] !=originalColor) return;

        image[r][c]=newColor;
        //top
        dfs(r-1, c, image, originalColor, newColor,n,m);
        //bottom
        dfs(r+1, c, image, originalColor, newColor, n,m);
        //left
        dfs(r, c-1, image, originalColor, newColor,n,m);
        //right
        dfs(r, c+1, image, originalColor, newColor,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor== color)return image;
        int n=image.size();
        int m=image[0].size();
        dfs(sr, sc, image, originalColor, color,n,m);
        return image;
    }
};
int main(){
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr=1, sc=1, color=2;
    vector<vector<int>> ans=s.floodFill(image, sr, sc, color);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void print(int arr[4][4]){
    int topR=0, bottomR=3,leftC=0, rightC=3;
    
    while(topR<=bottomR && leftC<= rightC){
        
        for(int i=leftC; i<=rightC; i++){
            cout<<arr[topR][i]<<" ";
        }
        topR++;

        for(int i=topR; i<=bottomR; i++){
            cout<<arr[i][rightC]<<" ";
        }
        rightC--;


        for(int i=rightC; i>=leftC; i--){
            cout<<arr[bottomR][i]<<" ";
        }
        bottomR--;


        for(int i=bottomR; i>=topR; i--){
            cout<<arr[i][leftC]<<" ";
        }
        leftC++;
    }
}
int main() {
 int arr[4][4]={{1,2,3,4},{12,13,14,5},{11,16,15,6}, {10,9,8,7}};
 print(arr);
}
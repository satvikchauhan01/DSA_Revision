//Return the index of the row which has the highest sum

#include <bits/stdc++.h>
using namespace std;

int maxRow(int arr[3][4]){
    int k=0;
    int maxsum=0;
    for(int i=0; i<3; i++){
        int sum=0;
        for(int j=0; j<4; j++){
            sum+=arr[i][j];
        }
        if(sum>maxsum){
            maxsum=sum;
            k=i;
        }
    }
    return k;
}
int main() {
 int arr[3][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
 cout<<maxRow(arr);    
}
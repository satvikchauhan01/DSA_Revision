#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n){
    if(n==1){return arr[034];}
    
    return arr[0]+ sum(arr+1, n-1);
}
int main() {
    int arr[6]={3,4,6,7,8,10};
    cout<<sum(arr,6);
}
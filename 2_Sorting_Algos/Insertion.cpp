#include <bits/stdc++.h>
using namespace std;
void Insertion(vector <int> &arr){
	int n=arr.size();
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
	vector <int> arr;
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(3);
	Insertion(arr);
	for(int i=0; i<5; i++){
		cout<<arr[i]<<" ";
	}
}
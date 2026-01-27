#include <iostream>
using namespace std;
#include <vector>
//Selection Sort:
void swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}
//void ss(int arr[]){
//	for(int i=0; i<4; i++){
//		int mini=i;
//		for(int j=i+1; j<5; j++){
//			if(arr[j]<arr[mini]){
//				mini=j;
//			}
//		}
//		swap(arr[mini],arr[i]);
//	}
//}
//int main(){
//	int arr[5]={4,2,8,12,3};
//	ss(arr);
//	for(int i=0; i<5; i++){
//		cout<<arr[i]<<" ";
//	}
//}
//----------------------------------------------------------------------------------------------------


//Buble Sort:
// move the largest element to the last by side by side comparison:
void Bubble(vector <int> &arr){
	int n=arr.size();
	for(int i=0; i<n-2; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main(){
	vector <int> arr;
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(3);
	Bubble(arr);
	for(int i=0; i<5; i++){
		cout<<arr[i]<<" ";
	}
}

#include <iostream>
using namespace std;
int listindex(int key, int arr[]){
	for(int i=0; i<5; i++){
		if(arr[i]==key){
			if(key>5){
				return key*2;
			}
			else{
				return key/2;
			}
		}
	}
	return -1;
}
int main(){
	int arr[5]={3,1,6,4,2};
	int index=listindex(6,arr);
	cout<<index;
}
 
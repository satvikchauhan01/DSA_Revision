#include <bits/stdc++.h> 
using namespace std;
void deleteSt(stack<int>&inputStack, int count, int size){
   if(inputStack.empty() || count==size){
      inputStack.pop();
      return;
   }
   int temp=inputStack.top();
   inputStack.pop();
   deleteSt(inputStack,count+1, size);
   inputStack.push(temp);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   int middle;
   if((N+1)%2==0){
      middle=(N+1)/2 -1;
    }
    else{
       middle=(N+1)/2;
    }
   deleteSt(inputStack,count,middle);
   
}
#include <bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==0)return;
    if(n%2!=0){
        n--;
    }
    print(n-2);
    cout<<n<<" ";

}
int printfact(int n){
    if(n==0 || n==1){return 1;}
    return n*printfact(n-1);
}


int power(int x, int n){
    if(n==0){return 1;}
    return x* power(x,n-1);
}

int fib(int n){
    if(n==0){return 0;}
    if(n==1){return 1;}

    return fib(n-1) + fib(n-2);
 }
int main() {
    int n=5;
    // print(n);

    cout<<printfact(n)<<endl;
    cout<<power(2,3)<<endl;
    cout<<fib(5);
}
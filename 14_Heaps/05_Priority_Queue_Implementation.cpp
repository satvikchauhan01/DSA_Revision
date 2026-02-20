#include <bits/stdc++.h>
#include <queue>
using namespace std;


int main(){
    // Create a priority queue (max-heap by default)
    priority_queue<int> pq;
    //
    priority_queue<int, vector<int>, greater<int>> min_pq; // Min-heap


    // Insert elements into the priority queue
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    // Display the top element (the largest element)
    cout << "Top element: " << pq.top() << endl; // Output: 20         //this happens by accesing the heap's root node

    // Remove the top element
    pq.pop();                                  //this happens by deleting the root node and replacing it with the last element, then heapifying down to restore the heap property

    // Display the new top element after popping
    cout << "Top element after pop: " << pq.top() << endl; // Output: 15
    cout<<boolalpha<<pq.empty()<<endl;
    cout<<pq.size()<<endl; 
    return 0;
}
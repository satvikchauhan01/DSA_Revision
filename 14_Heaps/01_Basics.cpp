/*
    A heap is a complete binary tree that satisfies the heap property.
    ->A complete binary tree is a binary tree in which all levels are completely filled except possibly the last level, which is filled from left to right. 
    ->The heap property states that for a max heap, every parent node is greater than or equal to its children, 
    ->a min heap, every parent node is less than or equal to its children.

    Note: A heap is not a binary search tree (BST). 

    If a node is at index i, 
        then its left child is at index 2*i and 
        its right child is at index 2*i+1  and 
        its parent is at index i/2 
    in 1-based indexing.

    if a node is at index i, 
        then its left child is at index 2*i+1 and 
        its right child is at index 2*i+2 and 
        its parent is at index (i-1)/2 
    in 0-based indexing.
*/
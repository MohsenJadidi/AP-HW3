#include<iostream>

#ifndef MAXHEAP_H
#define MAXHEAP_H

class Maxheap;
std::ostream& operator<<(std::ostream&, const Maxheap&);// Operator << for std::cout

class Maxheap
{

private:
    int heapSize;           // Current size of max heap
    int* array;             // Pointer to store array elements
    void MaxHeapfiy(int i); // Heapify a subtree
    void swap(int*, int*);  // Swap two inputs

public:
    Maxheap();              // Constructor 
    Maxheap(int [], int);   // Constructor 

    ~Maxheap();             // Desteructor

    void add(int);      // Adds a new key 
    void Delete();      // Deletes a key stored at root
    int parent(int);    // Returns input/2 (index of parent of node i)
    int left(int);      // Returns 2*input (index of left child of node i)
    int right(int);     // Returns 2*input + 1 (index of right child of node i)
    

    int getHeight();            // Returns Height of tree
    int Max(){return array[0];};// Returns key of max node(root)
    int Parent(int i){return array[parent(i)-1];}   // Return parent key of node i
    int RightChild(int i){return array[right(i)-1];}// Return right child key of node i
    int LeftChild(int i){return array[left(i)-1];}  // Return left child key of node i
    //
    int getHeapSize() const {return heapSize;}
    int getArray(int i) const {return array[i];}

};

#endif
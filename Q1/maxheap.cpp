#include"maxheap.h"
#include<cmath>

/* Constructor */
Maxheap::Maxheap()
{
    heapSize = 0;
    array = nullptr;

}

/* Constructor */
Maxheap::Maxheap(int arr[], int size)
{
    heapSize = size;
    array = new int[heapSize];
    
    for(int i{}; i < heapSize; i++)
    {
        array[i] = arr[i];
    }
    //MaxHeapfiy(0);

}

/* Destructor */
Maxheap::~Maxheap()
{
    delete[] array;
}

/* add key to heap and fix heeap property */
void Maxheap::add(int key)
{
    heapSize++;
    int* temp{new int[heapSize]};
    temp[heapSize-1] = key;

    for(int i{}; i < heapSize-1; i++)
    {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;

    // Fix the heap property if it is violated
    int i{heapSize-1};
    while (i != 0 && array[parent(i+1) - 1] < array[i]) 
    {   
       swap(&array[i], &array[parent(i+1) - 1]); 
       i = parent(i+1) - 1; 
    }  


}

/* return index of parent of node i */
int Maxheap::parent(int i)
{
    return (static_cast<int>(i/2));
}

/* index of left child of node i */
int Maxheap::left(int i)
{
    return 2*i;
}

/* index of right child of node i */
int Maxheap::right(int i)
{
    return (2*i + 1);
}

/*  A recursive method to heapify a subtree with the root at given index */ 
void Maxheap::MaxHeapfiy(int i)
{
    i++; // index start from 0

    int l{left(i)}; // left index
    int r{right(i)};    // right index
    int largest{i};

    if(l <= heapSize && array[l] > array[i])
    {
        largest = l;
    }
    if (r <= heapSize && array[r] > array[largest])
    {
        largest = r;
    }
    if (largest != i) 
    {
        swap(&array[i], &array[largest]);
    }
    MaxHeapfiy(largest);
}

/* Swap two inputs */
void Maxheap::swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

/* Returns Height of tree */
int Maxheap::getHeight()
{
    return static_cast<int>(std::log2(heapSize));
}

/* operator << for std::cout */
std::ostream& operator<<(std::ostream& os, const Maxheap& h)
{
    int heapSize{h.getHeapSize()};
    int len = 2;
    for(int i{}; i < heapSize; i++)
    {
        if(i < len-1)
        {
            os << h.getArray(i) << ",";
        }
        else
        {
            len *=2;
            os << std::endl << h.getArray(i) << ",";
        }
    }
    os << std::endl;

    return os;
}

// Method to remove minimum element (or root) from max heap 
void Maxheap::Delete() 
{ 

    //array[0] = array[heapSize-1]; 
    heapSize--; 
    //MaxHeapfiy(0); 
  
} 






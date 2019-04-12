#include<iostream>
#include"maxheap.h"


int main()
{   
	Maxheap h1{};
	h1.add(25);
	h1.add(32);
	h1.add(17);
	h1.add(23);
	h1.add(101);  
 
	std::cout << h1 << std::endl;  
	/* 
	101,
	32, 17,
	23, 25
	*/
	std::cout << h1.Parent(3) << std::endl; // 101
	std::cout << h1.LeftChild(1) << std::endl;  // 32
	std::cout << h1.RightChild(1) << std::endl;  // 17
	

	int arr[7] {23, 1, 7, 52, 11, 10, 75};
	Maxheap h2{arr, 7};
	std::cout << std::endl;
	std::cout << h2 << std::endl; 
 

    return 0;
}
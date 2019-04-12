#include<iostream>
#include"vector.h"


int main()
{   
    Vector v1{};    // Constructor
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(3);
    v1.show();
    v1.pop_back();
    v1.show();

    
    Vector v2{v1};  // Copy constuctor
    v2.push_back(5);
    v1.push_back(3);
    v2.show();
    v1.show();

    // +
    Vector v3{v1+v2};   // Copy constuctor and operator +
    std::cout << "Sum:\n";
    v3.show();

    // =
    v3 = v1;        // Operator = copy version
    v3.show();
    v3 = v1 + v2;   // Operator = move version
    v3.show();

    //
    Vector v4{std::move(v3)};   // Move constructor
    

    Vector v5{v1*v2};
    std::cout << "Internal product:\n";
    v5.show();


  
    // < == >

    std::cout << "== operator:\n";
    std::cout << (v1==v2) << std::endl;

    std::cout << "< operator:\n";
    std::cout << (v1<v2) << std::endl;



    return 0;
}
#include"vector.h"
#include<iostream>
#include<algorithm>

/* Constructor */
Vector::Vector()
{   
    std::cout << "# Constructor # \n";
    vector_capacity = 1;
    vector_size = 0;
    vector = nullptr;
}

/* Destructor */
Vector::~Vector()
{
    std::cout << "# Destructor # \n";
    delete[] vector;
}

/* Copy Constructor */
Vector::Vector(const Vector& vec)
{
    std::cout << "# Copy Constructor # \n";
    vector_capacity = vec.vector_capacity;
    vector_size = vec.vector_size;

    vector = new int[vector_size];

    for(int i{}; i < vector_size; i++)
    {
        vector[i] = vec.vector[i];
    }
    
}

/* Move Constructor */
Vector::Vector(Vector&& vec)
{
    std::cout << "# Move Constructor # \n";
    vector_capacity = vec.vector_capacity;
    vector_size = vec.vector_size;

    vector = vec.vector;
    vec.vector = nullptr;
}

/* Operator + */
Vector Vector::operator+(const Vector& right_vec)
{
    std::cout << "# Operator + # \n";
    Vector sum{*this};
    if(this->vector_size != right_vec.vector_size)
    {
        std::cout << "ERROR : vectors must be same size! (result is invalid)\n";
        for(int i {}; i < sum.vector_size; i++)
        {
            sum.vector[i] = 0;         
        }
        return sum;
    }

    for(int i {}; i < sum.vector_size; i++)
    {
        sum.vector[i] += right_vec.vector[i];         
    }
    return sum;
}

/* Operator * */
Vector Vector::operator*(const Vector& right_vec)
{
    std::cout << "# Operator * # \n";
    Vector sum{*this};
    if(this->vector_size != right_vec.vector_size)
    {
        std::cout << "ERROR : vectors must be same size! (result is invalid)\n";
        for(int i {}; i < sum.vector_size; i++)
        {
            sum.vector[i] = 0;         
        }
        return sum;
    }

    for(int i {}; i < sum.vector_size; i++)
    {
        sum.vector[i] *= right_vec.vector[i];         
    }
    return sum;
}

/* Operator == */
bool Vector::operator==(const Vector& right_vec)
{
    std::cout << "# Operator == # \n";
    return (vector_size == right_vec.vector_size);
}

/* Operator < */
bool Vector::operator<(const Vector& right_vec)
{
    std::cout << "# Operator < # \n";
    return (vector_size < right_vec.vector_size);
}

/* Operator > */
bool Vector::operator>(const Vector& right_vec)
{
    std::cout << "# Operator > # \n";
    return (vector_size > right_vec.vector_size);
}

/* Operator = copy version */
Vector& Vector::operator=(const Vector& vec)
{
    std::cout << "# Operator = copy version # \n";
    if(this == &vec)
    {
        return *this;
    }
    
    vector_size = vec.vector_size;
    vector_capacity = vec.vector_capacity;

    delete[] vector;

    for(int i{}; i < vector_size; i++)
    {
        vector[i] = vec.vector[i];
    }
    return *this;
}

/* Operator = move version */
Vector& Vector::operator=(Vector&& vec)
{
    std::cout << "# Operator = move version # \n";

    vector_size = vec.vector_size;
    vector_capacity = vec.vector_capacity;

    delete[] vector;
    vector = vec.vector;
    vec.vector = nullptr;

    return *this;
}

/* Adds a new element at the end of the vector */
void Vector::push_back(int input)
{
    int* temp{new int[++vector_size]};

    if(vector_capacity < vector_size)
    {
        vector_capacity *= 2;
    }

    for(int i{}; i < vector_size-1; i++)
    {
        temp[i] = vector[i];
    }
    
    temp[vector_size-1] = input;
    delete[] vector;
    vector = temp;
}

/* Remove element from a vector from end */
void Vector::pop_back()
{
    int* temp{new int[--vector_size]};
    if(vector_size <= (vector_capacity/2) )
    {
        vector_capacity /= 2;
    }

    for(int i{}; i < vector_size; i++)
    {
        temp[i] = vector[i];
    }
    delete[] vector;
    vector = temp;
}

/* Display vector */
void Vector::show()
{
    std::cout << "Vector : ";
    for(int i{}; i < vector_size; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl; 
    
}
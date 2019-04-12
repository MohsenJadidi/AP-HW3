
class Vector
{
private:
    int* vector;    // Pointer to array of elements

public:
    Vector();               // Constructor
    ~Vector();              // Destructor
    Vector(const Vector&);  // Copy Constructor
    Vector(Vector &&);      // Move Constructor

    /* Define operators */
    Vector operator+(const Vector&);
    Vector operator*(const Vector&);
    bool operator==(const Vector&);
    bool operator<(const Vector&);
    bool operator>(const Vector&); 

    Vector& operator=(const Vector&);   // Operator = copy version
    Vector& operator=(Vector&&);        // Operator = move version

    //  size_t N;
    int vector_capacity;    // Capacity of array    
    int vector_size;        // Current size of array
    
    void push_back(int);    // Adds a new element at the end of the vector
    void pop_back();        // Remove element from a vector from end

    void show();            // Display vector
};


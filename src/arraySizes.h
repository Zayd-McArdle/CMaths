/// @brief Used for defining the array type and size
typedef struct
{
    union
    {        
        int* intArray;
        double* doubleArray;
        long* longArray;
        long long* longlongArray;
    };    
    int size;
} ArraySize;


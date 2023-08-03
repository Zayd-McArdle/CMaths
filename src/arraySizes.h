#ifndef ARRAYSIZES_H
#define ARRAYSIZES_H
/// @brief Used for defining the array type and size
struct ArraySize
{
    union
    {        
        int* intArray;
        double* doubleArray;
        long* longArray;
        long long* longlongArray;
    };    
    int size;
};
#endif

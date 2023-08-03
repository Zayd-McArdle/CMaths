#include "range.h"
#define DECLARE_SMALLEST_LARGEST(dataType) dataType smallest, largest
#define CALCULATE largest - smallest
#define GET_RANGE(dataType, title) dataType get##title##Range(struct ArraySize* array) {\
    dataType smallest, largest;\
    for (int i = 0; i < array->size; i++)\
    {\
        if (array->dataType##Array[i] < smallest)\
        {\
            smallest = array->intArray[i];\
        }\
        else if (array->dataType##Array[i] > largest)\
        {\
            largest = array->dataType##Array[i];\
        }\
    }\
    return largest - smallest;\
}
GET_RANGE(int, Integer)
GET_RANGE(double, Double)
/*
int getRange(ArraySize* array)
{
    DECLARE_SMALLEST_LARGEST(int);
    for (int i = 0; i < array->size; i++)
    {
        if (array->intArray[i] < smallest)
        {
            smallest = array->intArray[i];
        }
        else if (array->intArray[i] > largest)
        {
            largest = array->intArray[i]; 
        }                
    }
    return CALCULATE;
    
}
double getRangeWithDecimals(ArraySize* array)
{
    DECLARE_SMALLEST_LARGEST(double);
    for (int i = 0; i < array->size; i++)
    {
        if (array->decimalArray[i] < smallest)
        {
            smallest = array->decimalArray[i];
        }
        else if (array->decimalArray[i] > largest)
        {
            largest = array->decimalArray[i]; 
        }                
    }
    return CALCULATE;
}
*/
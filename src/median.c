#include <math.h>
#include <stdlib.h>
#include "median_declarations.h"
#include "median_macros.h"
DECLARE_COMPARE_ARRAY_FUNCTIONS

COMPARE_ARRAY(int, Integer);
COMPARE_ARRAY(double, Double)
GET_MEDIAN(int, Integer)
GET_MEDIAN(double, Double)


/*
int getMedian(ArraySize* array) {
    int output;
    qsort(array->intArray, array->size, sizeof(int), compareIntegerArray);
    if (array->size % 2 == 0) {
        //Gets the middle index of the array
        int middleIndex = (array->size -1) / 2;
        //Sums the two middle values and divides it by 2 to get the median
        output = (array->intArray[middleIndex] + array->intArray[middleIndex + 1]) / 2;
    } else {
        //returns the middle value in the array
        output = array->intArray[round((array->size - 1) / 2)];
    }
    return output;
}
*/
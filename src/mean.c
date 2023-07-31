#include "mean.h"
#define GET_MEAN(dataType, title) dataType get##title##Mean(ArraySize* array) {\
    dataType output = 0;\
    for (int i = 0; i < array->size; i++)\
    {\
        output += array->dataType##Array[i];\
    }\
    return output / (array->size -1);\
}
GET_MEAN(int, Integer)
GET_MEAN(double, Double)

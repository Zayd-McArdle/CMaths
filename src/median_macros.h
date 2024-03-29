#ifndef MEDIAN_MACROS_H
#define MEDIAN_MACROS_H
#define ELEMENT_IS(dataType, element1, operator, element2) (*((const dataType*)(element1)) operator (*((const dataType*)(element2))))
#define COMPARE_ARRAY(dataType, title) static dataType compare##title##Array(const void* a, const void* b) {\
    if (ELEMENT_IS(dataType, a, <, b)) {\
        return -1;\
    }\
    else if (ELEMENT_IS(dataType, a, >, b)) {\
        return 1;\
    }\
    return 0;\
}
#define DECLARE_COMPARE_ARRAY_FUNCTIONS \
    COMPARE_ARRAY(int, Integer)\
    COMPARE_ARRAY(double, Double)
#define GET_MEDIAN(dataType, title) dataType get##title##Median(struct ArraySize* array) {\
    dataType output;\
    qsort(array->dataType##Array, array->size, sizeof(dataType), compare##title##Array);\
    if (array->size % 2 == 0)\
    {\
        int middleIndex = array->size - 1 / 2; \
        output = (array->dataType##Array[middleIndex] + array->dataType##Array[middleIndex + 1]) / 2; \
    }\
    else\
    {\
        output = array->dataType##Array[(int)round((array->size - 1) / 2)]; \
    }\
    return output; \
}
#endif
#ifndef MODE_H
#define MODE_H
#include "arraySizes.h"
struct Mode {
    union {
        int intValue;
        double doubleValue;
        long longValue;        
    };
    int frequency;
} ;
struct Mode* getIntegerMode(struct ArraySize* array);
struct Mode* getDoubleMode(struct ArraySize* array);
#endif
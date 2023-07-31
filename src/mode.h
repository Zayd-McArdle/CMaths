#include "arraySizes.h"
typedef struct
{
    int value;
    int frequency;
} Mode;
Mode* getIntegerMode(ArraySize* array);
Mode* getDoubleMode(ArraySize* array);
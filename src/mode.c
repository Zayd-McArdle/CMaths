#include "mode.h"
#include <stdlib.h>
static int findOccurrence(ArraySize* array, int value) {
    int occurrence = 0;
    for (int i = 0; i < array->size; i++)
    {
        if (array->intArray[i] == value)
        {
            occurrence++;
        }        
    }
    return occurrence;
    
}
#define SET_MODE(dataType, title) static inline void set##title##Mode(Mode* mode, ArraySize* array, int index) {\
    mode->value = array->dataType##Array[index];\
    mode->frequency = findOccurrence(array, array->dataType##Array[index]);\
}
#define GET_MODE(title) Mode* get##title##Mode(ArraySize* array) {\
    Mode* mode = NULL;\
    for (int i = 0; i < array->size; i++)\
    {\
        if (mode == NULL) {\
            mode = (Mode*)malloc(sizeof(Mode));\
            set##title##Mode(mode, array, i);\
            continue;\
        }\
        Mode tempMode;\
        set##title##Mode(&tempMode, array, i);\
        if (tempMode.value != mode->value && tempMode.frequency > mode->frequency)\
        {\
            mode->value = tempMode.value;\
            mode->frequency = tempMode.frequency;\
        }\
    }\
    return mode;\
}

SET_MODE(int, Integer)
SET_MODE(double, Double)
// static inline void setMode(Mode* mode, ArraySize* array, int index) {
//     mode->value = array->intArray[index];
//     mode->frequency = findOccurrence(array, array->intArray[index]);
// }
GET_MODE(Integer)
GET_MODE(Double)
// Mode* getMode(ArraySize* array) {       
//     Mode* mode = NULL;
//     for (int i = 0; i < array->size; i++)
//     {
//         //Initialise pointer if uninitialised.
//         if (mode == NULL)
//         {
//             mode = (Mode*)malloc(sizeof(Mode));
//             setMode(mode, array, i);
//             continue;
//         }        
//         Mode tempMode;
//         setMode(&tempMode, array, i);        
//         if (tempMode.value != mode->value && tempMode.frequency > mode->frequency)
//         {
//             mode->value = tempMode.value;
//             mode->frequency = tempMode.frequency;
//         }        
//     }
//     return mode;   
// }
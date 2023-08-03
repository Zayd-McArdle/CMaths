#include "mode.h"
#include <stdlib.h>
static int findOccurrence(struct ArraySize* array, int value) {
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
#define SET_MODE(dataType, title) static inline void set##title##Mode(struct Mode* mode, struct ArraySize* array, int index) {\
    mode->dataType##Value = array->dataType##Array[index];\
    mode->frequency = findOccurrence(array, array->dataType##Array[index]);\
}
#define GET_MODE(dataType, title) struct Mode* get##title##Mode(struct ArraySize* array) {\
    struct Mode* mode = NULL;\
    for (int i = 0; i < array->size; i++)\
    {\
        if (mode == NULL) {\
            mode = (struct Mode*)malloc(sizeof(struct Mode));\
            set##title##Mode(mode, array, i);\
            continue;\
        }\
        struct Mode tempMode;\
        set##title##Mode(&tempMode, array, i);\
        if (tempMode.dataType##Value != mode->dataType##Value && tempMode.frequency > mode->frequency)\
        {\
            mode->dataType##Value = tempMode.dataType##Value;\
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
GET_MODE(int, Integer)
GET_MODE(double, Double)
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
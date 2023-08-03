#include <stdio.h>
#include <stdlib.h>
#include "mean.h"
#include "median_declarations.h"
#include "mode.h"
#include "range.h"
const char* mathOptions[] = {
    "Mode",
    "Mean",
    "Median",
    "Range"
};
const char* digitOptions[] = {
    "Integers",
    "Decimals"
};
struct ArraySize dataCollection;
#pragma region Function Prototypes
static inline void showOptions(const char* options[], int size);
static inline void displayError(const char* options[], int size);
static inline void freeOldResources();
static void getIntegerCollection();
static void getDoubleCollection();
static void handleInput(int chosenOption, const char* options[]);
static void calculateDoubleArray(struct ArraySize* array);
#pragma endregion
static inline void showOptions(const char* options[], int size) {
    printf("Please select from the following options (numeric keys only):\n");    
    int chosenOption = 0;
    for (int i = 0; i < size; i++)
    {
        printf("%d)%s \n", chosenOption, options[i]);
    }
    if (scanf("%d", &chosenOption) != 1)
    {
        displayError(options, size);
    }
    else
    {
        handleInput(chosenOption, options);
    }
}
static void calculateDoubleArray(struct ArraySize* array) {
    double (*doMathOperations[4])(struct ArraySize*);
    doMathOperations[0] = getDoubleMean;
    doMathOperations[1] = getDoubleMedian;
    doMathOperations[3] = getDoubleRange;
    printf("What do you want to calculate\n");
    int chosenOption = 0;
    for (int i = 0; i < 4; i++)
    {
        printf("%d)%s \n", chosenOption, mathOptions[i]);
    }
    while (scanf("%d", &chosenOption) != 1 && (chosenOption < 1 || chosenOption > 4))
    {
        printf("Invalid Input. Please try again.\n");
    }
    for (int i = 0; i < 4; i++)
    {
        if (chosenOption == i-1)
        {
            double calculation = doMathOperations[i](array);
            printf("The answer is %lf", calculation);
            break;
        }
        else if (chosenOption == 3)
        {
            struct Mode* mode = getDoubleMode(array);
            printf("The mode is %lf.\n", mode->doubleValue);
            printf("The frequency of %lf is %d\n", mode->doubleValue, mode->frequency);
            free(mode);
            break;
        }                
    }
    
}
static inline void displayError(const char* options[], int size) {
    printf("Invalid option.\nPlease try again.");
    showOptions(options, size);
}
static inline void freeOldResources() {
    void* dynamicallyAllocatedResources[4] = {
        dataCollection.doubleArray,
        dataCollection.intArray,
        dataCollection.longArray,
        dataCollection.longlongArray
    };
    for (int i = 0; i < 4; i++)
    {
        free(dynamicallyAllocatedResources[i]);
    }
    
}
static void getIntegerCollection()
{
    freeOldResources();
    //int* dataCollection = NULL;
    
}
static void getDoubleCollection()
{
    freeOldResources();
    dataCollection.doubleArray = NULL;
    double inputtedValue;
    printf("Please enter a value (press enter when you are finished)");
    while (scanf("%lf", &inputtedValue) == 1)
    {
        dataCollection.size++;
        if (dataCollection.doubleArray == NULL) {
            dataCollection.doubleArray = (double*)malloc(sizeof(double) * dataCollection.size);            
            dataCollection.doubleArray[0] = inputtedValue;
        } else {
            double* tempArray = (double*) realloc(dataCollection.doubleArray, dataCollection.size * sizeof(double));
            if (tempArray == NULL)
            {
                //Memory allocation failed exiting function
                free(dataCollection.doubleArray);
                free(tempArray);
                return;
            }
            tempArray[dataCollection.size - 1] = inputtedValue;
            dataCollection.doubleArray = tempArray;
            free(tempArray);
        }   
    }
    calculateDoubleArray(&dataCollection);    
}
static void handleInput(int chosenOption, const char* options[]) {
    if (options == digitOptions)
    {
        if (chosenOption < 1 || chosenOption > 2)
        {
            displayError(options, 2);
        }                
    }
    else if (options == mathOptions)
    {
        if (chosenOption < 1 || chosenOption > 4)
        {
            displayError(options, 4);
        }
        else if (chosenOption == 1)
        {
            getIntegerCollection();
        }
        else if (chosenOption == 2)
        {
            getDoubleCollection();
        }
        
        
        
    }
    
    
}

int main(void){
    printf("CMaths Version 1.0");
    showOptions(digitOptions, 2);
    freeOldResources();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "arraySizes.h"
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
ArraySize dataCollection;
static inline void displayError(const char* options[]) {
    printf("Invalid option.\nPlease try again.");
    showOptions(options);
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
    int* dataCollection = NULL;
    
}
static int getDoubleCollection()
{
    freeOldResources();
    dataCollection.doubleArray == NULL;
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
                return 1;
            }
            tempArray[dataCollection.size - 1] = inputtedValue;
            dataCollection.doubleArray = tempArray;
            free(tempArray);
        }   
    }
    showOptions(mathOptions);
}

static void handleInput(int chosenOption, const char* options[]) {
    if (options == digitOptions)
    {
        if (chosenOption < 1 || chosenOption > 2)
        {
            displayError(options);
        }
        
    }
    else if (options == mathOptions)
    {
        if (chosenOption < 1 || chosenOption > 4)
        {
            displayError(options);
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
inline void showOptions(const char* options[]) {
    printf("Please select from the following options (numeric keys only):\n");    
    int chosenOption = 0;
    for (int i = 0; i < (sizeof(options) / sizeof(options[i])); i++)
    {
        printf("%d)%s \n", chosenOption, options[i]);
    }
    if (scanf("%d", &chosenOption) != 1)
    {
        displayError(options);
    }
    else
    {
        handleInput(chosenOption, options);
    }
}
int main(void){
    printf("CMaths Version 1.0");
    showOptions(digitOptions);
    freeOldResources();
    return 0;
}
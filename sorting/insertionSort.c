#include <stdio.h>
#include "../dataStructures/linkedList.h"
#include "insertionSort.h"

double* insertionSort(double arr[], int size){
    double* ret = sortWithLL(arr, size);
    return ret;
}
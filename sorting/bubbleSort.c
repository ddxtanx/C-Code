#include <stdio.h>
#include "../helperLibs/arrayFuncs.h"
#include "bubbleSort.h"
double* bubbleSort(double array[], int arrayLen){
	int swaps = 1;
	double* arr = copyArray(array, arrayLen);
	while(swaps != 0){
		swaps = 0;
		for(int x = 0; x<arrayLen-1; x++){
			double first = arr[x];
			double second = arr[x+1];
			if(first>second){
				arr[x] = second;
				arr[x+1] = first;
				swaps++;
			}
		}
	}
	return arr;
}


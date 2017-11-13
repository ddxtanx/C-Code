#include <stdio.h>
#include "../helperLibs/arrayFuncs.h"
#include "../helperLibs/memoryManage.h"
#include "../sorting/bubbleSort.h"

int main(int argv, char** argc){
	int arrayLen;
	printf("Enter length of array:\n");
	scanf("%i", &arrayLen);
	double* arr = initArray(arrayLen);
	double* arrSorted = bubbleSort(arr, arrayLen);
	printArray(arr, arrayLen);
	printArray(arrSorted, arrayLen);

	freeWrapper(arrSorted);
	freeWrapper(arr);
	ensureMallocs();
	return 0;
}

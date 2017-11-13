#include <stdio.h>
#include "../sorting/bubbleSort.h"

int main(int argv, char** argc){
	int arrayLen;
	printf("Enter length of array:\n");
	scanf("%i", &arrayLen);
	int arr[arrayLen];
	for(int x = 0; x<arrayLen; x++){
		int element;
		printf("Enter element #%i of the array.\n", x + 1);
		scanf("%i", &element);
		arr[x] = element;
	}
	bubbleSort(arr, arrayLen);
	for(int x = 0; x<arrayLen; x++){
		printf("Element %i of array is %i\n", x + 1, arr[x]);
	}
	return 0;
}

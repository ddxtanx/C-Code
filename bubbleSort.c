#include <stdio.h>
void bubbleSort(int array[], int arrayLen){
	int swaps = 1;
	while(swaps != 0){
		swaps = 0;
		for(int x = 0; x<arrayLen-1; x++){
			int first = array[x];
			int second = array[x+1];
			if(first>second){
				array[x] = second;
				array[x+1] = first;
				swaps++;
			}
		}
	}
}

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

#include <stdio.h>
#include "bubbleSort.h"
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


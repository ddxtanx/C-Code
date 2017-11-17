#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../sorting/quickSort.h"
#include "../helperLibs/arrayFuncs.h"
#include "../helperLibs/memoryManage.h"
#include <string.h>
int main(int argv, char** argc){
    int size, maxNum;
    srand(time(NULL));
    if(argv==3){
        size = atoi(argc[1]);
        maxNum = atoi(argc[2]);
    } else{
    printf("Size of array? ");
    scanf("%d", &size);

    printf("Max num? ");
    scanf("%d", &maxNum);
    }
    double* arr = randomArray(size, maxNum);
    printArray(arr, size);

    printf("Sorting...\n");
    double* sortedArr = quickSort(arr, size);
    printArray(sortedArr, size);

    freeWrapper(arr);
    freeWrapper(sortedArr);

    ensureMallocs();
    return 0;
}
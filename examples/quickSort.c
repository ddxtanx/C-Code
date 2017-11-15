#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../sorting/quickSort.h"
#include "../helperLibs/arrayFuncs.h"
#include "../helperLibs/memoryManage.h"
int main(){
    srand(time(NULL));
    int size;
    printf("Size of array? ");
    scanf("%d", &size);

    int maxNum;
    printf("Max num? ");
    scanf("%d", &maxNum);

    double* arr = randomArray(size, maxNum);
    printArray(arr, size);

    double* sortedArr = quickSort(arr, size);
    printArray(sortedArr, size);

    printf("Size of Original %d & size of Sorted %d\n", sizeOfArray(arr), sizeOfArray(sortedArr));
    freeWrapper(arr);
    freeWrapper(sortedArr);

    return 0;
}
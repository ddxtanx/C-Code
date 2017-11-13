arrayFuncs = ../helperLibs/arrayFuncs.c
memoryManage = ../helperLibs/memoryManage.c
linkedList = ../dataStructures/linkedList.c
binaryTree = ../dataStructures/binaryTree.c
heap = ../dataStructures/heap.c
bubbleSort: ../sorting/bubbleSort.c
	gcc -g bubbleSort.c ../sorting/bubbleSort.c -o bubbleSort
insertionSort: ../sorting/insertionSort.c $(arrayFuncs) $(memoryManage)
	gcc -g insertionSort.c ../sorting/insertionSort.c $(arrayFuncs) $(memoryManage) $(linkedList) -o insertionSort
all:
	make bubbleSort insertionSort
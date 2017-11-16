arrayFuncs = ../helperLibs/arrayFuncs.c
memoryManage = ../helperLibs/memoryManage.c
linkedList = ../dataStructures/linkedList.c
binaryTree = ../dataStructures/binaryTree.c
heap = ../dataStructures/heap.c
insertionSort = ../sorting/insertionSort.c
binaryTree: $(binaryTree) $(arrayFuncs) $(memoryManage) ../helperLibs/dectobinary.c
	gcc -g binaryTree.c $(binaryTree) $(arrayFuncs) $(memoryManage) ../helperLibs/dectobinary.c -o binaryTree.o
linkedList: $(linkedList) $(memoryManage) $(arrayFuncs)
	gcc -g linkedList.c $(linkedList) $(memoryManage) $(arrayFuncs) -o linkedList.o
bubbleSort: ../sorting/bubbleSort.c $(arrayFuncs) $(memoryManage)
	gcc -g bubbleSort.c ../sorting/bubbleSort.c $(arrayFuncs) $(memoryManage) -o bubbleSort.o
insertionSort: $(insertionSort) $(arrayFuncs) $(memoryManage) $(linkedList)
	gcc -g insertionSort.c $(insertionSort) $(arrayFuncs) $(memoryManage) $(linkedList) -o insertionSort.o
quickSort: ../sorting/quickSort.c $(arrayFuncs) $(memoryManage) $(linkedList) $(insertionSort)
	gcc -g quickSort.c ../sorting/quickSort.c $(arrayFuncs) $(memoryManage) $(insertionSort) $(linkedList) -o quickSort.o
arrayFuncs: $(arrayFuncs) $(memoryManage)
	gcc -g arrayFuncs.c $(arrayFuncs) $(memoryManage)  -o arrayFuncs.o
all:
	make bubbleSort insertionSort binaryTree linkedList quickSort arrayFuncs
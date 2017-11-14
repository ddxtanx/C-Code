arrayFuncs = ../helperLibs/arrayFuncs.c
memoryManage = ../helperLibs/memoryManage.c
linkedList = ../dataStructures/linkedList.c
binaryTree = ../dataStructures/binaryTree.c
heap = ../dataStructures/heap.c
insertionSort = ../sorting/insertionSort.c
binaryTree: $(binaryTree) $(arrayFuncs) $(memoryManage) $(linkedList) ../helperLibs/dectobinary.c
	gcc -g binaryTree.c $(binaryTree) $(arrayFuncs) $(memoryManage) $(linkedList) ../helperLibs/dectobinary.c -o binaryTree
linkedList: $(linkedList) $(memoryManage) $(arrayFuncs)
	gcc -g linkedList.c $(linkedList) $(memoryManage) $(arrayFuncs) -o linkedList
bubbleSort: ../sorting/bubbleSort.c $(arrayFuncs) $(memoryManage) $(linkedList)
	gcc -g bubbleSort.c ../sorting/bubbleSort.c $(arrayFuncs) $(memoryManage) $(linkedList)  -o bubbleSort
insertionSort: $(insertionSort) $(arrayFuncs) $(memoryManage) $(linkedList)
	gcc -g insertionSort.c $(insertionSort) $(arrayFuncs) $(memoryManage) $(linkedList) -o insertionSort
quickSort: ../sorting/quickSort.c $(arrayFuncs) $(memoryManage) $(linkedList) $(insertionSort)
	gcc -g quickSort.c ../sorting/quickSort.c $(arrayFuncs) $(memoryManage) $(linkedList) $(insertionSort) -o quickSort
arrayFuncs: $(arrayFuncs) $(memoryManage) $(linkedList)
	gcc -g arrayFuncs.c $(arrayFuncs) $(memoryManage) $(linkedList) -o arrayFuncs
all:
	make bubbleSort insertionSort binaryTree linkedList quickSort arrayFuncs
arrayFuncs = ../helperLibs/arrayFuncs.c
memoryManage = ../helperLibs/memoryManage.c
linkedList = ../dataStructures/linkedList.c
binaryTree = ../dataStructures/binaryTree.c
heap = ../dataStructures/heap.c
binaryTree: $(binaryTree) $(arrayFuncs) $(memoryManage) ../helperLibs/dectobinary.c
	gcc -g binaryTree.c $(binaryTree) $(arrayFuncs) $(memoryManage) ../helperLibs/dectobinary.c -o binaryTree
linkedList: $(linkedList) $(memoryManage) $(arrayFuncs)
	gcc -g linkedList.c $(linkedList) $(memoryManage) $(arrayFuncs) -o linkedList
bubbleSort: ../sorting/bubbleSort.c $(arrayFuncs) $(memoryManage)
	gcc -g bubbleSort.c ../sorting/bubbleSort.c $(arrayFuncs) $(memoryManage) -o bubbleSort
insertionSort: ../sorting/insertionSort.c $(arrayFuncs) $(memoryManage)
	gcc -g insertionSort.c ../sorting/insertionSort.c $(arrayFuncs) $(memoryManage) $(linkedList) -o insertionSort
all:
	make bubbleSort insertionSort binaryTree linkedList
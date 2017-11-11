linkedList: arrayFuncs.c memoryManage.c
	gcc -g linkedList.c arrayFuncs.c memoryManage.c -o linkedList
binaryTree: memoryManage.c arrayFuncs.c dectobinary.c
	gcc -g binaryTree.c dectobinary.c memoryManage.c arrayFuncs.c -o binaryTree
heapSort: memoryManage.c
	gcc -g heapSort.c memoryManage.c -o heapSort
all:
	make linkedList binaryTree heapSort
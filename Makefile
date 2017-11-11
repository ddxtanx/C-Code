linkedList: ./helperLibs/arrayFuncs.c ./helperLibs/memoryManage.c
	gcc -g ./dataStructures/linkedList.c ./helperLibs/arrayFuncs.c ./helperLibs/memoryManage.c -o ./dataStructures/linkedList
binaryTree: ./helperLibs/memoryManage.c ./helperLibs/arrayFuncs.c ./helperLibs/dectobinary.c
	gcc -g ./dataStructures/binaryTree.c ./helperLibs/dectobinary.c ./helperLibs/memoryManage.c ./helperLibs/arrayFuncs.c -o ./dataStructures/binaryTree
heap: ./helperLibs/memoryManage.c
	gcc -g ./dataStructures/heap.c ./helperLibs/memoryManage.c -o ./dataStructures/heap
all:
	make linkedList binaryTree heap
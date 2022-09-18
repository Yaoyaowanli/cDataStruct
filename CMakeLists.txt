cmake_minimum_required(VERSION 3.19)
project(C_SeqList C)

set(CMAKE_C_STANDARD 99)

add_executable(C_SeqList cmake-build-debug/源文件/main.c cmake-build-debug/源文件/SeqList/SeqList.c cmake-build-debug/头文件/SeqList-h/SeqList.h cmake-build-debug/源文件/SList/SList.c cmake-build-debug/头文件/SList-h/SList.h cmake-build-debug/源文件/List/List.c cmake-build-debug/头文件/List/List.h cmake-build-debug/源文件/Stack/Stack.c cmake-build-debug/头文件/Stack-h/Stack.h cmake-build-debug/源文件/Queue/Queue.c cmake-build-debug/头文件/Queue-h/Queue.h cmake-build-debug/源文件/Heap/Heap.c cmake-build-debug/头文件/Heap-h/Heap.h cmake-build-debug/源文件/Sort/HeapSort/HeapSort.c cmake-build-debug/头文件/Sort-h/Sort.h cmake-build-debug/源文件/TopK/TopK.c cmake-build-debug/头文件/TopK-h/TopK.h cmake-build-debug/源文件/BinaryTree/BinaryTree.c cmake-build-debug/头文件/BinaryTree-h/BinaryTree.h)
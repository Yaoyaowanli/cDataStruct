//
// Created by 姚远 on 2022/9/16.
//

#ifndef C_SEQLIST_HEAP_H
#define C_SEQLIST_HEAP_H

#endif //C_SEQLIST_HEAP_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;


//初始化
void HeapInit(Heap* php,HPDataType* a,int n);
//销毁
void HeapDestroy(Heap* php);
//插入
void HeapPush(Heap* php,HPDataType x);
//弹出
void HeapPop(Heap* php);
//取堆顶数据
HPDataType HeapTop(Heap* php);

//堆排序
void HeapSort(HPDataType* a,int n);
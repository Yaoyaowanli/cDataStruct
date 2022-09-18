//
// Created by 姚远 on 2022/9/18.
//

#ifndef C_SEQLIST_TOPK_H
#define C_SEQLIST_TOPK_H

#endif //C_SEQLIST_TOPK_H
typedef int DataType;
#include <assert.h>

//将数组最小的k个元素放到数组0-k位置。
void TopMinK(DataType * a,int k,int size);

//将数组最大的k个元素放到数组0-k位置。
void TopMaxK(DataType * a,int k,int size);


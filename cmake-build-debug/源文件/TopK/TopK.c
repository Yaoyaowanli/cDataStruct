//
// Created by 姚远 on 2022/9/18.
//

#include "../../头文件/TopK-h/TopK.h"

void Swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//大堆向下调整
void MaxHeapAdJustDown(DataType* a,int size,int root){
    assert(a);
    int parent = root;
    int child = root*2+1;

    while(child < size){
        //在左右孩子节点中找较大的
        if(child+1 < size && a[child+1]>a[child]){
            child++;
        }
        //比较如果子大于父就交换
        if (a[parent] < a[child]){
            Swap(&a[parent],&a[child]);
            //迭代
            parent = child;
            child = parent*2+1;
        } else {
            //如果父节点大于子节点说明就是大堆
            break;
        }
    }
}

//小堆向下调整
void MinHeapAdJustDown(DataType* a,int size,int root){
    assert(a);
    int parent = root;
    int child = root*2+1;

    while(child < size){
        //在左右孩子节点中找较小的
        if(child+1 < size && a[child+1] < a[child]){
            child++;
        }
        //比较如果子小于父就交换
        if (a[parent] > a[child]){
            Swap(&a[parent],&a[child]);
            //迭代
            parent = child;
            child = parent*2+1;
        } else {
            //如果父节点小于子节点说明就是小堆
            break;
        }
    }
}

//构建大堆
void MaxHeapInit(DataType* a,int size){
    assert(a);
    //构建大堆
    for(int i=(size-1-1)/2 ; i>=0 ; i--){
        MaxHeapAdJustDown(a,size,i);
    }
}

//构建小堆
void MinHeapInit(DataType* a,int size){
    assert(a);
    //构建小堆
    for(int i=(size-1-1)/2 ; i>=0 ; i--){
        MinHeapAdJustDown(a,size,i);
    }
}

//选最小的topK个数
void TopMinK(DataType * a,int k,int size){
    //1、把数组前k个数变成一个大堆
    MaxHeapInit(a,k);
    //2、让其遍历数组
    for (int i=k ; i<size ; i++){
        //a[k]和堆顶元素比，如果比堆顶元素小，就进堆再向下调整
        if (a[0] > a[i]){
            Swap(&a[0],&a[i]);
            //调整
            MaxHeapAdJustDown(a,k,0);
        }
    }
    //3、最后堆中就是最小的k个数
}


//将数组最大的k个元素放到数组0-k位置。
void TopMaxK(DataType * a,int k,int size){
    //1、把数组前k个数变成一个小堆
    MinHeapInit(a,k);
    //2、让其遍历数组
    for (int i=k ; i<size ; i++){
        //a[k]和堆顶元素比，如果比堆顶元素大，就进堆再向下调整
        if (a[0] < a[i]){
            Swap(&a[0],&a[i]);
            //调整
            MinHeapAdJustDown(a,k,0);
        }
    }
    //3、最后堆中就是最大的k个数
}

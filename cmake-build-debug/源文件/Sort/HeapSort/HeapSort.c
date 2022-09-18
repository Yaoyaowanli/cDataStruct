//
// Created by 姚远 on 2022/9/17.
//

#include "/Users/yaoyuan/C:C++_Code/CDataStruct/cmake-build-debug/头文件/Sort-h/Sort.h"

//向下调整
void AdJustDown(int* arr,int size,int root){
    int parent = root;     //i是每一次向下调整的根节点
    int child = root*2+1;  //child是左孩子节点，也是默认节点
    //最多调整到叶子节点
    while(child < size) {
        //判断左右孩子节点哪个比较大，孩子节点就取哪个
        if (child+1 <size && arr[child] < arr[child + 1]) {
            child++;
        }
        //判断父节点小于孩子节点就交换
        if (arr[parent] < arr[child]) {
            int tmp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = tmp;
            //迭代：交换完成后需要进入到下一个子树
            parent = child;
            child = parent * 2 + 1;
        } else {   //如果父节点大于子节点，就说嘛他本身就是一个大根堆，直接break
            break;
        }
    }
}


//堆排升序
void MyHeapSort(int* arr,int size){
    //1、构建堆
    //i从最后一颗子树开始一次向前进行向下调整算法
    for (int i = (size-1)-1/2 ; i>=0 ; i--){
        AdJustDown(arr,size,i);
    }

    //2、每次取堆顶元素（最大的数）和数组最后元素交换，缩小数组范围，最终形成升序
    int end = size-1;

    while(end > 0 ){ //走到最后下标0的元素不需要在排序了
        int tmp = arr[end];
        arr[end] = arr[0];
        arr[0] = tmp;
        //进行一次向下调整
        AdJustDown(arr,end,0);
        end--;
    }
}
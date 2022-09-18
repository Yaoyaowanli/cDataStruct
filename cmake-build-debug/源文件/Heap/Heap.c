//
// Created by 姚远 on 2022/9/16.
//

#include "../../头文件/Heap-h/Heap.h"

void swap (HPDataType* p1,HPDataType* p2){
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


//向下调整算法   前提：左右子树都是小堆
void AdJustDowm(HPDataType* a,int n,int root){
    int parent = root;
    //默认左孩子较小
    int child = root*2 +1;

    //child的下标不能超过数组的长度
    while(child < n){
        //如果右孩子小于左孩子，就选择右孩子
        if (child+1 < n && a[child+1] < a[child]){
            child++;
        }

        //比较,如果孩子小于父亲，就交换
        if (a[child] < a[parent]){
            swap(&a[child],&a[parent]);
            //迭代
            parent = child;
            child = parent*2+1;
        }else{
            break;
        }
    }
}

//向上调整
void AdJustUp(HPDataType* a, int n, int child){
    //1、
    int parent = (child-1)/2;
    while(child > 0){
        if (a[parent] > a[child]){
            swap(&a[parent],&a[child]);
            child = parent;
            parent = (child-1)/2;
        }else{
            break;
        }
    }

}


//初始化
void HeapInit(Heap* php,HPDataType* a,int n){
    php->_a = (HPDataType*) malloc(sizeof(HPDataType)*n);
    if (php->_a == NULL){
        printf("HeapInit: malloc failed ! \n");
        exit(-1);
    }
    memcpy(php->_a,a, sizeof(HPDataType)*n);
    php->_size = n;
    php->_capacity = n;

    //构建堆
    for(int i = (n-1-1)/2 ; i>=0 ; i--){
        AdJustDowm(php->_a,php->_size,i);
    }
}


//销毁
void HeapDestroy(Heap* php){
    assert(php);
    free(php->_a);
    php->_size = 0;
    php->_capacity = 0;
}

//检查容量，不够就增容
void CheckHeapCap(Heap* php){
    if (php->_size == php->_capacity){
        void* new= realloc(php->_a, sizeof(HPDataType)*php->_capacity*2);
        if (new == NULL){
            printf("CheckHeapCap: realloc php->_a failed !\n");
            return;
        }
        php->_a = (HPDataType*)new;
        php->_capacity *= 2;
        return;
    }
}

//插入
void HeapPush(Heap* php,HPDataType x){
    assert(php);
    //check capacity
    CheckHeapCap(php);
    if (php->_capacity == php->_size){
        printf("CheckHeapCap: realloc php->_a failed !\n");
        return;
    }
    php->_a[php->_size++] = x;

    //向上调整
    AdJustUp(php->_a,php->_size,php->_size-1);
}


//弹出
void HeapPop(Heap* php){
    assert(php);
    assert(php->_size>0);
    //1、让首尾交换
    swap(&php->_a[0],&php->_a[php->_size-1]);
    //2、size--
    php->_size--;
    //3、向下调整
    AdJustDowm(php->_a,php->_size,0);
}


//取堆顶数据
HPDataType HeapTop(Heap* php){
    assert(php);
    assert(php->_size>0);
    return php->_a[0];
}


void HeapSort(HPDataType* a,int n){
    //1、建堆,找到数组中完全二叉树的最后一颗子树开始向下调整,完成后再--到上一个子树，直到根节点执行完毕，建堆就完成了
    for (int i=(n-1-1)/2 ; i>=0 ; i--){
        AdJustDowm(a,n,i);
    }


    //2、每次把堆顶的最小数据和数组最后一个数交换，然后缩小数组-1，再对小堆进行一次向下调整，再将堆顶数据与数组最后一个数交换。。。
    int end = n-1;
    while (end>0){
        swap(&a[0],&a[end]);
        AdJustDowm(a,end,0);
        end--;
    }
}
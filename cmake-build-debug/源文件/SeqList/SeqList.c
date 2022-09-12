//
// Created by 姚远 on 2022/9/7.
//

#include "../../头文件/SeqList-h/SeqList.h"

//初始化
void SeqListInit(SL* ps){
    ps->a = malloc(sizeof(SLDataType)*4);
    if (ps->a == NULL){
        printf("SeqListInit : malloc s.a failed \n");
        exit(-1);
    }

    ps->size = 0;
    ps->capacity = 4;
}

//打印
void SeqListPrint(SL* ps){
    assert(ps);

    for (int i=0;i< ps->size; i++){
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}

//检查容量，不够扩容
void SeqListCheckCapacity(SL* ps){
    assert(ps);
    //检查内存如果满了就需要增容
    if (ps->size >= ps->capacity){
        ps->capacity *=2;
        ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
    }
    //判断错误
    if (ps->a == NULL){
        printf("SeqListPushBack: realloc failed ~");
        exit(-1);
    }
}



//尾部插入
void SeqListPushBack(SL* ps,SLDataType x){
    assert(ps);
    SeqListCheckCapacity(ps);

    ps->a[ps->size]=x;
    ps->size++;
}
//尾部删除
void SeqListPopBack(SL* ps){
    assert(ps);

    ps->size--;
}
//头部插入
void SeqListPushFront(SL* ps,SLDataType x){
    assert(ps);
    SeqListCheckCapacity(ps);

    //挪动数据
    int end = ps->size-1;
    while (end >= 0){
        ps->a[end+1] = ps->a[end];
        end--;
    }

    ps->a[0]=x;
    ps->size++;

}
//头部删除
void SeqListPopFront(SL* ps){
    assert(ps);

    //挪动数据
    int i = 0;
    while (i <= ps->size-2){
        ps->a[i]=ps->a[i+1];
        i++;
    }
    ps->size--;
}
//任意位置插入(不以下标为基准)
void SeqListInsert(SL* ps,int pos,SLDataType x){
    assert(ps);
    SeqListCheckCapacity(ps);
    //验证pos的合法性
    if (pos < 1 || pos > ps->size){
        printf("SeqListInsert: pos is bad parameter !\n");
        return;
    }
    // 1 2 3 4 5
    //   6
    int end = pos-1;
    int start = ps->size-1;
    while (start >= end) {
        ps->a[start+1]=ps->a[start];
        start--;
    }

    ps->a[end]=x;
    ps->size++;
}
//任意位置删除
void SeqListErase(SL* ps,int pos){
    assert(ps);
    //验证pos的合法性
    if (pos < 1 || pos > ps->size){
        printf("SeqListErase: pos is bad parameter !\n");
        return;
    }

    int start = pos-1;
    int end = ps->size-1;
    while (start < end){
        ps->a[start]=ps->a[start+1];
        start++;
    }
    ps->size--;
}

//查找位置
int SeqListFind(SL* ps,SLDataType x){
    assert(ps);

    for (int i = 0;i<ps->size;i++){
        if (ps->a[i]==x){
            return i+1;
        }
    }
    return -1;
}

//销毁
void SeqListDestory(SL* ps){
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;

}
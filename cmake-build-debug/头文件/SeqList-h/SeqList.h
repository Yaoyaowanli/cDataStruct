//
// Created by 姚远 on 2022/9/7.
//

#ifndef C_SEQLIST_SEQLIST_H
#define C_SEQLIST_SEQLIST_H

#endif //C_SEQLIST_SEQLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N 10
typedef int SLDataType;


//顺序表，有效数据在数组中必须是连续的
typedef struct SqeList{
    SLDataType* a;
    int  size;
    int  capacity;

}SL,SqeList;


//初始化
void SeqListInit(SL* ps);
//销毁
void SeqListDestory(SL* ps);
//打印
void SeqListPrint(SL* ps);
//检查容量，不够扩容
void SeqListCheckCapacity(SL* ps);
//尾部插入
void SeqListPushBack(SL* ps,SLDataType x);
//尾部删除
void SeqListPopBack(SL* ps);
//头部插入
void SeqListPushFront(SL* ps,SLDataType x);
//头部删除
void SeqListPopFront(SL* ps);
//任意位置插入
void SeqListInsert(SL* ps,int pos,SLDataType x);
//任意位置删除
void SeqListErase(SL* ps,int pos);
//查找位置
int SeqListFind(SL* ps,SLDataType x);
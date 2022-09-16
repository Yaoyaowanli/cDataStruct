//
// Created by 姚远 on 2022/9/12.
//

#ifndef C_SEQLIST_QUEUE_H
#define C_SEQLIST_QUEUE_H

#endif //C_SEQLIST_QUEUE_H

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QueueNode{
    struct QueueNode* _next;
    QDataType _data;
}QueueNode;

typedef struct Queue{
    QueueNode* _head;
    QueueNode* _tail;
}Queue;


//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//尾插
void QueuePush(Queue* pq,QDataType x);
//头删
void QueuePop(Queue* pq);
//取头数据
QDataType QueueFront(Queue* pq);
//取尾数据
QDataType QueueBack(Queue* pq);
//是否为空
int QueueEmpty(Queue* pq);
//求长度
int QueueSize(Queue* pq);
//
// Created by 姚远 on 2022/9/8.
//

#ifndef C_SEQLIST_SLIST_H
#define C_SEQLIST_SLIST_H

#endif //C_SEQLIST_SLIST_H
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;

typedef struct SListNode{
    SListDataType data;
    struct SListNode* next;
}SListNode;




//接口列表

//尾部插入
void SListPushBack(struct SListNode** ppHead,SListDataType x);
//尾部删除
void SListPopBack(struct SListNode** ppHead);
//头部插入
void SListPushFront(struct SListNode** ppHead,SListDataType x);
//头部删除
void SListPopFront(struct SListNode** ppHead);
//打印链表
void SListPrint(struct SListNode* pHead);
//查找节点
struct SListNode* SListFind(struct SListNode* pHead,SListDataType x);
//在pos节点之后插入
void SListInsertAfter(struct SListNode* pos,SListDataType x);
//在pos节点之后删除
void SListEraseAfter(struct SListNode* pos,SListDataType x);


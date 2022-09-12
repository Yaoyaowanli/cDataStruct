//
// Created by 姚远 on 2022/9/12.
//

#ifndef C_SEQLIST_LIST_H
#define C_SEQLIST_LIST_H

#endif //C_SEQLIST_LIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int LTDataType;

typedef struct ListNode{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;


//初始化
//void ListInit(ListNode** pphead);
ListNode* ListInit();
//清除数据
void ListClear(ListNode* phead);
//消除链表
void ListDestory(ListNode** pphead);
//打印
void ListPrint(ListNode* phead);
//尾插
void ListPushBack(ListNode* phead,LTDataType x);
//尾删
void ListPopBack(ListNode* phead);
//头插
void ListPushFront(ListNode* phead,LTDataType x);
//头删
void ListPopFront(ListNode* phead);
//查找
ListNode* ListFind(ListNode* phead,LTDataType x);
//任意位置之前插入
void ListInsert(ListNode* pos,LTDataType x);
//删除指定值的节点
void ListErase(ListNode* pos);

//
// Created by 姚远 on 2022/9/12.
//

#include "../../头文件/List/List.h"


//构造函数
ListNode* BuyListNode(LTDataType x){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->prev = NULL;
    return newNode;
}

//打印链表
void ListPrint(ListNode* phead){
    assert(phead);
    if (phead->next == phead){
        printf("List is empty !\n");
        return;
    }
    ListNode *cur = phead->next;
    while(cur != phead){
        printf("%d  ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//初始化
/*
void ListInit(ListNode** pphead){
    *pphead = BuyListNode(0);
    (*pphead)->next = *pphead;
    (*pphead)->prev = *pphead;
}
*/
ListNode* ListInit(){
    ListNode* phead = BuyListNode(0);
    phead->next=phead;
    phead->prev=phead;
    return phead;
}
//清除数据
void ListClear(ListNode* phead){
    assert(phead);

    ListNode *cur = phead->next;
    while(cur != phead){
        ListNode *next = cur->next;
        free(cur);
        cur = next;
    }

    phead->next = phead;
    phead->prev = phead;
}
//销毁链表
void ListDestory(ListNode** pphead){
    assert(*pphead);

    ListClear(*pphead);
    free(*pphead);
    *pphead = NULL;
}


//尾插
void ListPushBack(ListNode* phead,LTDataType x){
    assert(phead);

    ListNode* tail = phead->prev;
    ListNode* newNode = BuyListNode(x);
    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = phead;
    phead->prev = newNode;
}

//尾删
void ListPopBack(ListNode* phead){
    assert(phead);
    assert(phead->next != phead);

    ListNode *delete = phead->prev;
    ListNode *newTail = delete->prev;
    newTail->next = phead;
    phead->prev = newTail;
    free(delete);
}

//头插
void ListPushFront(ListNode* phead,LTDataType x){
    assert(phead);
    ListNode *oldHead = phead->next;
    ListNode *newHead = BuyListNode(x);

    newHead->next = oldHead;
    oldHead->prev = newHead;
    phead->next = newHead;
}
//头删
void ListPopFront(ListNode* phead){
    assert(phead);
    assert(phead->next != phead);

    ListNode *deleteNode = phead->next;
    ListNode *newHead = deleteNode->next;

    phead->next = newHead;
    newHead->prev = phead;

    free(deleteNode);
}


//查找
ListNode* ListFind(ListNode* phead,LTDataType x) {
    assert(phead);

    ListNode *cur = phead->next;
    while (cur != phead){
        if (cur->data == x){
            return cur;
        }
        cur = cur->next;
    }
    printf("not found !\n");
    return NULL;
}


//任意位置之前插入
void ListInsert(ListNode* pos,LTDataType x){
    assert(pos);

    ListNode *newNode = BuyListNode(x);
    ListNode *posPrev = pos->prev;
    posPrev->next = newNode;
    newNode->prev = posPrev;
    newNode->next = pos;
    pos->prev = newNode;
}


//删除指定的节点
void ListErase(ListNode* pos){
    assert(pos);
    //assert(pos != pos->next);

    ListNode *posPrev = pos->prev;
    ListNode *posNext = pos->next;

    posPrev->next = posNext;
    posNext->prev = posPrev;

    free(pos);
}
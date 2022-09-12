//
// Created by 姚远 on 2022/9/8.
//

#include "../../头文件/SList-h/SList.h"


//构造函数
SListNode* BuySListNode(SListDataType x){
    struct SListNode* newNode = (struct SListNode*)malloc(sizeof(struct SListNode));
    if (newNode == NULL){
        printf("SListPushBack: malloc newNode failed !\n");
        exit(-1);
    }
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

//打印链表
void SListPrint(struct SListNode* pHead){
    //assert(pHead);
    if (pHead == NULL){
        printf("SListPrint: SList is empty !\n");
        return;
    }
    SListNode* cur = pHead;
    while(cur != NULL){
        printf("%d -> ",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

//尾部插入
void SListPushBack(struct SListNode** ppHead,SListDataType x){
    struct SListNode* newNode = BuySListNode(x);
    if (*ppHead == NULL){
        *ppHead = newNode;
        return;
    }

    //找到尾部
    struct SListNode* tail = *ppHead ;
    while (tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
}

//尾部删除
void SListPopBack(struct SListNode** ppHead){
    //空节点的情况
    if (*ppHead == NULL){
        printf("SListPopBack: SList is empty !\n");
        return;
    }
    //只有一个节点的情况，就直接把头节点置空。
    if ((*ppHead)->next == NULL){
        free(*ppHead);
        *ppHead = NULL;
        return;
    }
    //不只一个节点的情况，拿到头节点
    struct SListNode* head = *ppHead;
    while ((head->next)->next != NULL){
        head = head->next;
    }
    free(head->next);
    head->next = NULL;
}

//头部插入
void SListPushFront(struct SListNode** ppHead,SListDataType x){
    struct SListNode* newNode = BuySListNode(x);
    //空节点的情况
    if (*ppHead == NULL){
        *ppHead = newNode;
        return;
    }
    newNode->next = *ppHead;
    *ppHead = newNode;
}

//头部删除
void SListPopFront(struct SListNode** ppHead){
    //空节点的情况
    if (*ppHead == NULL){
        printf("SListPopFront: SList is empty !\n");
        return;
    }
    //只有一个节点
    if ((*ppHead)->next == NULL){
        free(*ppHead);
        *ppHead = NULL;
        return;
    }
    //至少有两个节点
    struct SListNode* newHead = (*ppHead)->next;
    free(*ppHead);
    *ppHead = newHead;
}

//查找节点
struct SListNode* SListFind(struct SListNode* pHead,SListDataType x){
    if (pHead == NULL){
        printf("SListFind: SList is empty!\n");
        return pHead;
    }
    struct SListNode* cur = pHead;
    while (cur != NULL){
        if (cur->data == x){
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

//在pos节点之后插入
void SListInsertAfter(struct SListNode* pos,SListDataType x){
    assert(pos);

    struct SListNode* newNode = BuySListNode(x);
    newNode->next = pos->next;
    pos->next = newNode;
}

//在pos节点之后删除
void SListEraseAfter(struct SListNode* pos,SListDataType x){
    assert(pos);

    if (pos->next != NULL){
        struct SListNode* node = pos->next;
        pos->next = node->next;
        free(node);
    }

}




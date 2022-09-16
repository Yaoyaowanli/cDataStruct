//
// Created by 姚远 on 2022/9/12.
//

#include "../../头文件/Queue-h/Queue.h"


//初始化
void QueueInit(Queue* pq){
    assert(pq);

    pq->_head = pq->_tail = NULL;

}
//销毁
void QueueDestroy(Queue* pq){
    assert( pq);

    QueueNode *cur = pq->_head;
    while (cur){
        QueueNode *next = cur->_next;
        free(cur);
        cur = next;
    }
    pq->_head = pq->_tail = NULL;
}
//入队列
void QueuePush(Queue* pq,QDataType x){
    assert(pq);
    //创建一个新节点
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL){
        printf("QueuePush: malloc newNode failed !\n");
        return;
    }
    newNode->_data = x;
    newNode->_next = NULL;


    if (pq->_head == NULL){
        pq->_head = pq->_tail = newNode;
    }else{
        pq->_tail->_next = newNode;
        pq->_tail = newNode;
    }
}
//头删/出队列
void QueuePop(Queue* pq){
    assert(pq);

    if (pq->_head == NULL){
        printf("QueuePop: Queue is empty!\n");
        return;
    }

    QueueNode *cur = pq->_head;
    if(pq->_head->_next==NULL){
        free(cur);
        pq->_head = pq->_tail = NULL;
    } else{
        pq->_head = cur->_next;
        free(cur);
    }
}
//取头数据
QDataType QueueFront(Queue* pq){
    assert(pq);
    assert(pq->_head);
    return pq->_head->_data;
}
//取尾数据
QDataType QueueBack(Queue* pq){
    assert(pq);
    assert(pq->_tail);

    return pq->_tail->_data;
}
//是否为空
int QueueEmpty(Queue* pq){
    assert(pq);
    return pq->_head == NULL ? 1:0;
}
//求长度
int QueueSize(Queue* pq){
    assert(pq);

    int size = 0 ;
    QueueNode *cur = pq->_head;
    while (cur != NULL){
        size++;
        cur = cur->_next;
    }
    return size;
}
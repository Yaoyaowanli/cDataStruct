//
// Created by 姚远 on 2022/9/12.
//

#ifndef C_SEQLIST_STACK_H
#define C_SEQLIST_STACK_H

#endif //C_SEQLIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack{
    int* _a;
    int _top;       //栈顶下标
    int _capacity;
}Stack;

//初始化
void StackInit(Stack* pst);
//销毁
void StackDestory(Stack* pst);
//压栈
void StackPush(Stack* pst,STDataType x);
//出栈
void StackPop(Stack* pst);
//返回size
int StackSize(Stack* pst);
//判断是否为空
int StackEmpty(Stack* pst);
//获取栈顶数据
STDataType StackTop(Stack* pst);
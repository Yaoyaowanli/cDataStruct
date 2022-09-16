//
// Created by 姚远 on 2022/9/12.
//

#include "../../头文件/Stack-h/Stack.h"


//初始化
void StackInit(Stack* pst){
    assert(pst);

    pst->_a = malloc(sizeof(STDataType)*5);
    pst->_top = 0;
    pst->_capacity = 5;
}

//销毁
void StackDestory(Stack* pst){
    assert(pst);
    free(pst->_a);
    pst->_a = NULL;
    pst->_capacity = 0;
    pst->_top = 0;
}

//压栈
void StackPush(Stack* pst,STDataType x){
    assert(pst);
    //check capacity
    if (pst->_top == pst->_capacity -1){
        pst->_capacity *= 2;
        STDataType* tmp = (STDataType*) realloc(pst->_a, sizeof(STDataType) * pst->_capacity );
        if (tmp == NULL){
            printf("StackPush: realloc pst->a failed !");
            exit(-1);
        }else{
            pst->_a = tmp;
        }
    }

    pst->_a[pst->_top] = x;
    pst->_top++;

}

//出栈
void StackPop(Stack* pst){
    assert(pst);
    if (pst->_top <= 0){
        printf("StackPop: Stack is empty !\n");
        return;
    }
    pst->_top--;
}

//返回size
int StackSize(Stack* pst){
    assert(pst);

    return pst->_top;
}

//判断是否为空
int StackEmpty(Stack* pst){
    assert(pst);

    return pst->_top == 0 ? 1:0 ;
}

//获取栈顶数据
STDataType StackTop(Stack* pst){
    assert(pst);

    if (StackEmpty(pst)){
        printf("StackTop: Stack is empty !\n");
        return NULL;
    }
    return pst->_a[pst->_top-1];
}
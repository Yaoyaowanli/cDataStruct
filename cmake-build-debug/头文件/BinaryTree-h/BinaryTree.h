//
// Created by 姚远 on 2022/9/18.
//

#ifndef C_SEQLIST_BINARYTREE_H
#define C_SEQLIST_BINARYTREE_H

#endif //C_SEQLIST_BINARYTREE_H
#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef char BTDataType;

typedef struct BinaryTreeNode{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;



//返回节点个数
int TreeSize(BTNode* root);

//前序遍历
void PrevOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历
void PostOrder(BTNode* root);

//返回叶子节点个数
int TreeLeafSize(BTNode* root);
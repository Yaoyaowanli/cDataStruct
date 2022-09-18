//
// Created by 姚远 on 2022/9/18.
//

#include "../../头文件/BinaryTree-h/BinaryTree.h"



//返回叶子节点个数
int TreeLeafSize(BTNode* root){
    if (root->_left == NULL && root->_right ==NULL){
        return 1;
    }else{
        return TreeLeafSize(root->_left)+ TreeLeafSize(root->_right);
    }
}


//返回节点个数
int TreeSize(BTNode* root){
    if (root == NULL){
        return 0;
    }else{
        return 1+ TreeSize(root->_left)+ TreeSize(root->_right);
    }
}

//前序遍历
void PrevOrder(BTNode* root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    printf("%c ",root->_data);
    PrevOrder(root->_left);
    PrevOrder(root->_right);
}

//中序遍历
void InOrder(BTNode* root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    InOrder(root->_left);
    printf("%c ",root->_data);
    InOrder(root->_right);
}

//后序遍历
void PostOrder(BTNode* root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    PostOrder(root->_left);
    PostOrder(root->_right);
    printf("%c ",root->_data);
}
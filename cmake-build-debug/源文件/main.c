#include "../头文件/SeqList-h/SeqList.h"
#include "../头文件/SList-h/SList.h"
#include "../头文件/List/List.h"
#include "../头文件/Stack-h/Stack.h"
#include "../头文件/Queue-h/Queue.h"
#include "../头文件/Heap-h/Heap.h"
#include "/Users/yaoyuan/C:C++_Code/CDataStruct/cmake-build-debug/头文件/Sort-h/Sort.h"
#include "../头文件/TopK-h/TopK.h"
#include "../头文件/BinaryTree-h/BinaryTree.h"





//测试头尾的插入删除
void TestSeqList1(){
    SqeList s;
    SeqListInit(&s);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushBack(&s,4);
    SeqListPushBack(&s,5);
    SeqListPushBack(&s,6);
    SeqListPushBack(&s,7);
    SeqListPushBack(&s,8);
    SeqListPushBack(&s,9);
    SeqListPushBack(&s,10);
    SeqListPushBack(&s,11);
    SeqListPrint(&s);

    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPrint(&s);

    SeqListPushFront(&s,66);
    SeqListPushFront(&s,77);
    SeqListPushFront(&s,88);
    SeqListPushFront(&s,99);
    SeqListPrint(&s);

    SeqListPopFront(&s);
    SeqListPopFront(&s);
    SeqListPopFront(&s);
    SeqListPrint(&s);

    SeqListInsert(&s,2,77);
    SeqListInsert(&s,3,88);
    SeqListInsert(&s,4,99);
    SeqListPrint(&s);
    SeqListInsert(&s,1,55);
    SeqListInsert(&s,12,111);
    SeqListPrint(&s);
    SeqListErase(&s,5);
    SeqListPrint(&s);
    SeqListErase(&s,1);
    SeqListPrint(&s);
    SeqListErase(&s,8);
    SeqListPrint(&s);
    printf("%d\n",SeqListFind(&s,66));
    printf("%d\n",SeqListFind(&s,1));
    printf("%d\n",SeqListFind(&s,4));
    printf("%d\n",SeqListFind(&s,99));


    SeqListDestory(&s);

}


void TestSList1(){
    SListNode* psList = NULL;
    SListPushBack(&psList,1);
    SListPopBack(&psList);
    SListPrint(psList);
    SListPopBack(&psList);
    printf("------------------------------------------------------------------------\n");


    SListPushBack(&psList,1);
    SListPushBack(&psList,2);
    SListPrint(psList);

    SListPopBack(&psList);
    SListPopBack(&psList);
    SListPrint(psList);

    printf("------------------------------------------------------------------------\n");

    SListPushBack(&psList,1);
    SListPushBack(&psList,2);
    SListPushBack(&psList,3);
    SListPushBack(&psList,4);
    SListPushBack(&psList,5);
    SListPushBack(&psList,6);
    SListPushBack(&psList,7);
    SListPushBack(&psList,8);
    SListPushBack(&psList,9);
    SListPushBack(&psList,10);
    SListPushBack(&psList,11);
    SListPrint(psList);
    SListPopBack(&psList);
    SListPopBack(&psList);
    SListPopBack(&psList);
    SListPopBack(&psList);
    SListPopBack(&psList);
    SListPopBack(&psList);

    SListPrint(psList);
    printf("------------------------------------------------------------------------\n");

}

void TestSList2(){
    printf("testing SListPushFront and SListPopFront :\n");
    SListNode* psList = NULL;
    SListPushFront(&psList,5);
    SListPushFront(&psList,4);
    SListPushFront(&psList,3);
    SListPushFront(&psList,2);
    SListPushFront(&psList,1);
    SListPrint(psList);
    SListPopFront(&psList);
    SListPopFront(&psList);
    SListPopFront(&psList);
    SListPopFront(&psList);
    SListPrint(psList);
    SListPopFront(&psList);
    SListPrint(psList);
    SListPopFront(&psList);
    SListPushFront(&psList,1);
    SListPushFront(&psList,2);
    SListPrint(psList);
    SListPushFront(&psList,3);
    SListPushFront(&psList,4);
    SListPushFront(&psList,5);
    SListPrint(psList);

    SListNode* find = SListFind(psList,3);
    if (find == NULL){
        printf("not find !\n");
        return;
    }
    printf("find data is: %d\n",find->data);

}

void TestList1(){
    ListNode * pHead = ListInit();
    ListPushBack(pHead,1);
    ListPushBack(pHead,2);
    ListPushBack(pHead,3);
    ListPushBack(pHead,4);
    ListPushBack(pHead,5);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);

    ListPushFront(pHead,5);
    ListPushFront(pHead,4);
    ListPushFront(pHead,3);
    ListPrint(pHead);
    ListPushFront(pHead,2);
    ListPushFront(pHead,1);
    ListPrint(pHead);
    ListPopFront(pHead);
    ListPopFront(pHead);
    ListPopFront(pHead);
    ListPopFront(pHead);
    ListPrint(pHead);
    ListPopFront(pHead);
    ListPrint(pHead);


}

void TestList2(){
    ListNode * pHead = ListInit();
    ListPushBack(pHead,1);
    ListPushBack(pHead,2);
    ListPushBack(pHead,3);
    ListPushBack(pHead,4);
    ListPushBack(pHead,5);
    ListPrint(pHead);


    ListNode * pos = ListFind(pHead,3);
    ListInsert(pos,30);
    ListPrint(pHead);

    pos = ListFind(pHead,30);
    ListErase(pos);
    ListPrint(pHead);

}

void TestStack1(){
    Stack st ;
    StackInit(&st);

    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,3);
    StackPush(&st,4);
    StackPush(&st,5);

    while (! StackEmpty(&st)){
        printf("%d   ", StackTop(&st));
        StackPop(&st);
    }
    printf("\n");

    StackDestory(&st);
}

void TestQueue1(){
    Queue que ;
    QueueInit(&que);
    QueuePush(&que,1);
    QueuePush(&que,2);
    QueuePush(&que,3);
    QueuePush(&que,4);
    QueuePush(&que,5);
    printf("queue lens is: %d \n", QueueSize(&que));
    printf("%d ", QueueFront(&que));
    QueuePop(&que);
    printf("%d ", QueueFront(&que));
    QueuePop(&que);
    printf("%d ", QueueFront(&que));
    QueuePop(&que);
    printf("%d ", QueueFront(&que));
    QueuePop(&que);
    printf("%d ", QueueFront(&que));
    QueuePop(&que);
    printf("queue is empty?  %d\n", QueueEmpty(&que));
    printf("--------------------------------------------------\n");
    QueuePush(&que,1);
    QueuePush(&que,2);
    QueuePush(&que,3);
    QueuePush(&que,4);
    QueuePush(&que,5);
    /*printf("queue size is : %d\n", QueueSize(&que));
    printf("%d ",QueueBack(&que));
    QueuePop(&que);
    printf("%d ",QueueBack(&que));
    QueuePop(&que);
    printf("%d ",QueueBack(&que));
    QueuePop(&que);
    printf("%d ",QueueBack(&que));
    QueuePop(&que);
    printf("%d ",QueueBack(&que));
    QueuePop(&que);*/

    QueueDestroy(&que);
}


void TestHeap1(){
    int arr[] = {93,80,48,18,30,72,53,36,15,35,45};
    Heap hp;
    HeapInit(&hp,arr, sizeof(arr)/ sizeof(arr[0]));

    for (int i =0 ; i< hp._size ; i++){
        printf("%d ",hp._a[i]);
    }
    printf("\n-------------------------------\n");
    HeapPush(&hp,13);
    for (int i =0 ; i< hp._size ; i++){
        printf("%d ",hp._a[i]);
    }
    HeapDestroy(&hp);
}

void TestHeapSort1(){
    int arr[] = {93,80,48,18,30,72,53,36,15,35,45};
    int n = sizeof(arr)/ sizeof(arr[0]);
    MyHeapSort(arr,n);
    for (int i=0; i<n;i++){
        printf("%d  ",arr[i]);
    }
}


void TestTopK1(){
    int arr[] = {93,80,48,18,30,72,53,36,15,35,45,123,421,3,55,2,99,14,33,66};
    int k = 5;
    TopMinK(arr,k, sizeof(arr)/ sizeof(arr[0]));
    printf("TopMinK ：");
    for (int i=0; i<k;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");

    printf("TopMaxK ：");
    TopMaxK(arr,k,sizeof(arr)/ sizeof(arr[0]));
    for (int i=0; i<k;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}




BTNode* CreateNode(int x){
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    node->_data = x;
    node->_left = node->_right = NULL;
    return node;
}


void TestBinaryTree1(){
    BTNode *a = CreateNode('A');
    BTNode *b = CreateNode('B');
    BTNode *c = CreateNode('C');
    BTNode *d = CreateNode('D');
    BTNode *e = CreateNode('E');

    a->_left = b;
    a->_right = c;
    b->_left = d;
    b->_right = e;
    PrevOrder(a);
    printf("\n");
    InOrder(a);
    printf("\n");
    PostOrder(a);
    printf("\n");

    printf("TreeSize = %d\n", TreeSize(a));
    printf("TreeSize = %d\n", TreeSize(a));



    printf("TreeLeafSize = %d\n", TreeLeafSize(a));
    printf("TreeLeafSize = %d\n", TreeLeafSize(d));

}


int main() {
    //TestSeqList1();
    //TestSList1();
    //TestSList2();
    //TestList1();
    //TestList2();
    //TestStack1();
    //TestQueue1();
    //TestHeap1();
    //TestHeapSort1();
    //TestTopK1();
    TestBinaryTree1();

    return 0;
}


/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    List.h
 * @brief   
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-17 19:26:00
 ****************************************************************/
#ifndef _LIST_H__
#define _LIST_H__

#include "DefPublic.h"

class List {
public:
    List(){};
    ~List(){};
    // 逆序存放nums，如nums=[1,2,3,4,5]，在List中的顺序将为[5,4,3,2,1]
    void Insert(std::vector<int> nums);
    // 从头打印List
    void Print();
    // 计算两个List的和，存放进result
    static void Addition(List* l1, List* l2, List& result);
private:
    struct ListNode* Head = NULL;
    struct ListNode* Tail = NULL;
};

#endif // _LIST_H__
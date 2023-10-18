/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    DefPublic.h
 * @brief   
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-17 19:30:05
 ****************************************************************/
#ifndef _DEFPUBLIC_H__
#define _DEFPUBLIC_H__

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::vector<int> GetElement(char* argv, char symbol);            //分离出整数数组。

#endif // _DEFPUBLIC_H__
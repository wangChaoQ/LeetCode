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
#include <string.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::vector<int> GetElement(char* argv, char symbol);           // 分离出整数数组。
int lengthOfLongestSubstring(std::string s);                    // 返回不含有重复字符的 最长子串 的长度
bool isExist(std::string s, char ch);                           // 检查字符s中是否有ch字符
void MergeArrays(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& Nums);            // 将两个正序数组合合并成一个正序数组
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);              // 寻找两个正序数数组的中位数

#endif // _DEFPUBLIC_H__
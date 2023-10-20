/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
 *****************************************************************
 * @file    DefPublic.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-17 19:32:27
 ****************************************************************/

#include <sstream>
#include <stdio.h>
#include <string.h>
#include "DefPublic.h"

using namespace std;

vector<int> GetElement(char *argv, char symbol)
{
    vector<int> nums;
    stringstream str(argv);
    string item;

    while (getline(str, item, symbol))
    {
        int number = stoi(item);
        nums.push_back(number);
    }
    return nums;
}

bool isExist(string s, char ch)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == ch)
            return true;
    }
    return false;
}

int lengthOfLongestSubstring(string s)
{
    // 确认一下收到的字符串是否正确
    int len = 1, count = 0; // 函数的返回值
    string substr;

    for (int i = 0, j = 0; i < s.length();)
    {
        if (!isExist(substr, s[i])) // 不存在此字符
        {
            substr += s[i];
            count++;
            i++;
        }
        else
        {
            cout << "substr = " << substr << endl;
            len = (len > count ? len : count);
            j++;
            i = j;
            substr.clear();
            count = 0;
        }
    }
    cout << "substr = " << substr << endl;
    len = (len > count ? len : count); // 防止只有一个字符的情况,和遍历到最后的字符是最长的情况
    return len;
}

void MergeArrays(vector<int> &nums1, vector<int> &nums2, vector<int> &Nums)
{
    int i, j;
    for (i = 0, j = 0; i < nums1.size() && j < nums2.size();)
    {
        Nums.push_back(nums1[i] < nums2[j] ? nums1[i] : nums2[j]);
        if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    while (i < nums1.size())
    {
        Nums.push_back(nums1[i++]);
    }
    while (j < nums2.size())
    {
        Nums.push_back(nums2[j++]);
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int size = nums1.size() + nums2.size();
    float index1 = 0.0f, index2 = 0.0f;
    if (size % 2)
    {
        index1 = size / 2;
    }
    else
    {
        index1 = size / 2 - 1;
        index2 = size / 2;
    }

    vector<int> Nums;
    MergeArrays(nums1, nums2, Nums);
    for (int i = 0; i < Nums.size(); i++)
    {
        if (index2 == 0.0f && i == index1)
        {
            return Nums[i];
        }
        if (index2 != 0.0f && i == index1)
        {
            return (Nums[i] + Nums[i + 1]) / 2.0f;
        }
    }
    return 0;
}

string longestPalindrome(string s)
{
    int size = s.length();
    // 初始化一个
    vector<vector<bool>> dynamic(size, vector<bool>(size, false));

    // 因为每一个字符都必定是回文，初始化为true
    for (int i = 0; i < size; i++)
    {
        dynamic[i][i] = true;
    }

    // 初始化
    int maxlen = 1;
    int sentry = 0;
    // // 输出二维数组的状态
    // for(vector<bool> a : dynamic)
    // {
    //     for(bool b : a)
    //     {
    //         cout << b;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int len = 2; len < size + 1; len++)
    {
        for(int i = 0; i < size - len + 1; i++)
        {
            int j = i + len - 1;
            if(s[i] == s[j] && (len == 2 || dynamic[i + 1][j - 1]))
            {
                dynamic[i][j] = true;
                maxlen = maxlen > len ? maxlen : len;
                if(maxlen > len)
                    sentry = i;
            }
        }
    }

    // // 输出二维数组的状态
    // for(vector<bool> a : dynamic)
    // {
    //     for(bool b : a)
    //     {
    //         cout << b;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return s.substr(sentry, maxlen);
}
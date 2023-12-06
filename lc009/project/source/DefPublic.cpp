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
#include <iomanip> // 包含 setprecision 函数的头文件
#include <cmath>
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

std::string convert(std::string s, int numRows)
{
    // if(numRows == 1)
    //     return s;

    std::string strArray[numRows];      // 创建numRows个字符串数组，每个字符串保存每行的字符

    // int column = (numRows - 1) * 2;     // 小心numRows == 1时，完整行的间距不满足这个式子,所以要单独考虑 numRows == 1 的情况
    int column = pow(2, (numRows - 1));     // 这个式子包含所有情况，不需要单独考虑numRows == 1 的情况

    for(int i = 0; i < s.length(); i++)     // 遍历每个元素
    {
        for(int row = 0; row < numRows; row++)
        {
            if (row == 0 || row == numRows - 1)
            {
                if(column * i + row < s.length())
                    strArray[row] += s[column * i + row];
            }
            else
            {
                if(column * i + row - row * 2 < s.length())
                    strArray[row] += s[column * i - row];
                    // strArray[row] += s[column * i + row - row * 2];
                if(column * i + row < s.length())
                    strArray[row] += s[column * i + row];
            }
        }
    }

    std::string zstr;
    for(int row = 0; row < numRows; row++)
    {
        cout << strArray[row] << endl;
        zstr += strArray[row];
    }
    cout << zstr << endl;
    return zstr;
}

int reverse(int x)
{
    int max = pow(2, 31) - 1;
    int min = -pow(2, 31);
    // std::cout << "max:" << max << std::endl;
    // std::cout << "min:" << min << std::endl;
    int y = 0;
    
    while(x)
    {
        if (y < min / 10 || y > max / 10)           // /10很关键，不做/10处理，可能y就算已经超过32位，但低32位的值任在范围内，如1534236469
        {
            return 0;
        }
        
        y = (y*10 + x%10);
        x = x / 10;
    }
    std::cout << y << std::endl;
    return y;
}

int myAtoi(std::string s)
{
    std::cout << "s = " << s << std::endl;
    std::cout << "s size = " << s.size() << std::endl;
    // 找到第一个有效字符打头的子字符串
    std::string sub;
    bool start = false;
    int i = 0;
    for(; i < s.size(); i++)
    {
        if(isExist("0", s[i]))            // 排除0打头无效的字符串
        {
            start = true;
            continue;
        }
        if(!start && isExist(" ", s[i]))            // 排除空格打头无效的字符串
            continue;
        if(start)
        {
            if(isExist("123456789", s[i]))
                break;
            else
                return 0;
        }
        else
        {
            if(!isExist("123456789+-", s[i]))   // 找到第一个有效字符，如果还没找到就出现其他字符，返回0
                return 0;
            else
                break;
        }
    }
    sub += s[i];
    // 截断处理
    for(i++; i < s.size(); i++)
    {
        if(!isExist("1234567890.", s[i]))   // 中途出现其他字符，需要截断
            break;
        sub += s[i];
    }
    std::cout << "sub = " << sub << std::endl;
    std::cout << "sub size = " << sub.size() << std::endl;

    // 只有一个符号
    if(sub.size() == 0 && isExist("-+", s[0]))
        return 0;
    // 最后的值计算
    long result = 0;
    i = 0;
    if(sub[0] == '+' || sub[0] == '-')
        i = 1;
    std::cout << "start index = " << i << std::endl;
    for(;i < sub.size(); i++)
    {
        if(sub[i] == '\0')
            break;
        result = result * 10 + sub[i] - 48;
        if(result > pow(2, 31))
            break;
    }

    if(sub[0] != '-')
    {
        return (result > pow(2, 31) - 1) ? (pow(2, 31) - 1) : result;
    }
    else
    {
        return result > pow(2, 31) ? -pow(2, 31) : -result;
    }
}

bool isPalindrome(int x)
{
    // 负数去除
    if(x < 0)
        return false;

    int backx = x;
    long reversex = 0;

    while(x > 0)
    {
        reversex = reversex * 10 + x % 10;
        x = x / 10;
    }

    if(backx == reversex)
        return true;
    return false;
}
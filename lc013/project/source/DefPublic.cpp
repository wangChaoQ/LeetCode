/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    DefPublic.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-12-08 10:29:14
 ****************************************************************/
#include "DefPublic.h"

#include <iostream>
#include <algorithm> 
#include <stdio.h>

using namespace std;

int printVector2(vector<vector<int>>& vector2)
{
    for (int i = 0; i < vector2.size(); ++i) {
        for (int j = 0; j < vector2[i].size(); ++j) {
            printf("%d\t", vector2[i][j]);
        }
        cout << endl;
    }
    return 0;
}

int maxArea(vector<int>& height)
{
#if 0               //动态规划，容易踩内存
    // for(const auto& element : height)
    // {
    //     cout << element << endl;
    // }

    vector<vector<int>> dynamic(height.size(), vector<int>(height.size(), 0));

    // printVector2(dynamic);
    int shortBoard = 0;
    int Area = 0, maxArea = 0;

    for(int i = 0; i < height.size(); i++)
        for(int j = i + 1; j < height.size(); j++)
        {
            shortBoard = height[i] > height[j] ? height[j] : height[i];
            Area = shortBoard * (j - i);
            maxArea = maxArea > Area ? maxArea : Area;
        }
    // printVector2(dynamic);
    printf("maxArea :%d\n", maxArea);
    return maxArea;
#else            // 贪心算法
    int Area = 0, h = 0;
    int left = 0, right = height.size() - 1;
    while(left != right)
    {
        h = height[left] > height[right] ? height[right] : height[left];
        Area = Area > h*(right - left) ? Area : h*(right - left);
        if(height[left] > height[right])
            right --;
        else
            left ++;
    }
    return Area;
#endif
}

string intToRoman(int num)
{
    string Roman;
    int M, D, C, L, X, V, I = 0;
    
    M = num / 1000;
    while(M--)
        Roman += 'M';
    num %= 1000;

    C = num / 100;
    if(C == 9)
    {
        Roman += "CM";
        num -= 900;
    }
    else if(C == 4)
    {
        Roman += "CD";
        num -= 400;
    }

    D = num / 500;
    while(D--)
        Roman += 'D';
    num %= 500;

    C = num / 100;
    while(C--)
        Roman += 'C';
    num %= 100;

    X = num / 10;
    if(X == 9)
    {
        Roman += "XC";
        num -= 90;
    }
    else if(X == 4)
    {
        Roman += "XL";
        num -= 40;
    }
    

    L = num / 50;
    while(L--)
        Roman += 'L';
    num %= 50;

    X = num / 10;
    while(X--)
        Roman += 'X';
    num %= 10;

    I = num / 1;
    if(I == 9)
    {
        Roman += "IX";
        num -= 9;
    }
    else if(I == 4)
    {
        Roman += "IV";
        num -= 4;
    }
    V = num / 5;
    while(V--)
        Roman += 'V';
    num %= 5;

    I = num / 1;
    while(I--)
        Roman += 'I';

    // cout << "Roman:" << Roman << endl;
    return Roman;
}

int romanToInt(std::string s)
{
    cout << "s:" << s << endl;
    int result = 0;
    int M, D, C, L, X, V, I = 0;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        cout << "s[" << i << "]:" << s[i] << endl;
        if(s[i] == 'I')
        {
            result += 1;
            continue;
        }
        if(s[i] == 'V')
        {
            if(i >= 1 && s[i-1] == 'I')
            {
                result += 4;
                i--;
                continue;
            }
            result += 5;
            continue;
        }
        if(s[i] == 'X')
        {
            if(i >= 1 && s[i-1] == 'I')
            {
                result += 9;
                i--;
                continue;
            }
            result += 10;
            continue;
        }
        if(s[i] == 'L')
        {
            if(i >= 1 && s[i-1] == 'X')
            {
                result += 40;
                i--;
                continue;
            }
            result += 50;
            continue;
        }
        if(s[i] == 'C')
        {
            if(i >= 1 && s[i-1] == 'X')
            {
                result += 90;
                i--;
                continue;
            }
            result += 100;
            continue;
        }
        if(s[i] == 'D')
        {
            if(i >= 1 && s[i-1] == 'C')
            {
                result += 400;
                i--;
                continue;
            }
            result += 500;
            continue;
        }
        if(s[i] == 'M')
        {
            if(i >= 1 && s[i-1] == 'C')
            {
                result += 900;
                i--;
                continue;
            }
            result += 1000;
            continue;
        }
    }
    cout << "result:" << result << endl;
    return result;
}

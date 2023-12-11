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


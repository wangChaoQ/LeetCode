/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    TwoSum.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-16 15:19:26
 ****************************************************************/
#include <iostream>
#include "TwoSum.h"

using namespace std;

vector<int> TwoSum::twoSum(vector<int>& nums, int target) {
    int index1 = 0, index2 = 0;
    vector<int> result;
    for (int index1 = 0; index1 < nums.size(); index1++)
    {
        for (int index2 = index1 + 1; index2 < nums.size(); index2++)
        {
            if(nums[index1] + nums[index2] == target)
            {
                result.push_back(index1);
                result.push_back(index2);
                return result;
            }
        }
    }
    return result;
}
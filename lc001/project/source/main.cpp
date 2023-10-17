/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    main.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-16 14:47:58
 ****************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include "TwoSum.h"
#include "Split.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Wrong number of parameters!!!" << endl;
        exit(-1);
    }

    vector<int> nums;
    int target = std::stoi(argv[2]);
    // 对入参进行读取，存放
    Split split;
    nums = split.GetElement(argv[1], ',');
    // 运行计算
    TwoSum ts;
    vector<int> result = ts.twoSum(nums, target);
    // 结果打印检验
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
        cout << *it << endl;

    cout << "Hello World" << endl;
    return 0;
}
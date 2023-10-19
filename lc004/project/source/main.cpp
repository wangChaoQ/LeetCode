/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    main.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-18 10:22:44
 ****************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "DefPublic.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Wrong number of parameters!!!" << endl;
        exit(-1);
    }
    // 对入参进行读取，存放
    vector<int> nums1 = GetElement(argv[1], ',');
    vector<int> nums2 = GetElement(argv[2], ',');
    double result = findMedianSortedArrays(nums1, nums2);

    printf("result :%f\n", result);

    return 0;
}
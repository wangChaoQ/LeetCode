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
#include "DefPublic.h"
#include "List.h"

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
    // 创建两个链表，存储入参
    List l1, l2, result;
    l1.Insert(nums1);
    l2.Insert(nums2);
    l1.Print();
    l2.Print();
    List::Addition(&l1, &l2, result);

    result.Print();

    cout << "Hello World" << endl;
    return 0;
}
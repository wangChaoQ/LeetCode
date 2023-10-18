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
#include <iostream>
#include <sstream>
#include "DefPublic.h"

using namespace std;

vector<int> GetElement(char* argv, char symbol) {
    vector<int> nums;
    stringstream str(argv);
    string item;

    while(getline(str, item, symbol)) {
        int number = stoi(item);
        nums.push_back(number);
    }
    return nums;
}
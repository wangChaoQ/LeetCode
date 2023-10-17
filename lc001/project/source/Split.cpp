/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    Split.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-16 15:52:05
 ****************************************************************/
#include <iostream>
#include <sstream>
#include "Split.h"

using namespace std;


vector<int> Split::GetElement(char* argv, char symbol) {
    vector<int> nums;
    stringstream str(argv);
    string item;

    while(std::getline(str, item, symbol)) {
        int number = std::stoi(item);
        nums.push_back(number);
    }
    return nums;
}
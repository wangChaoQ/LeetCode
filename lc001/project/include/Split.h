/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    Split.h
 * @brief   
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-16 15:51:39
 ****************************************************************/
#ifndef _SPLIT_H__
#define _SPLIT_H__

#include <vector>

using namespace std;

class Split {
public:
    Split(){};
    ~Split(){};
    vector<int> GetElement(char* argv, char symbol);            //分离出整数数组。
private:
    
};

#endif // _SPLIT_H__
/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    main.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-12-08 10:30:27
 ****************************************************************/
#include "DefPublic.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> strs;
    for(int i = 1; i < argc; i++)
    {
        strs.push_back(atoi(argv[i]));
    }
    // for(int i = 0; i < strs.size(); i++)
    // {
    //     cout << strs[i] << endl;
    // }

    vector<vector<int>> result = threeSum(strs);
    printVector2(result);

}


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
#include <cmath>
#include "DefPublic.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Wrong number of parameters!!!" << endl;
        exit(-1);
    }
    // 对入参进行读取，存放
    std::string s = argv[1];

    int res = myAtoi(s);

    std::cout << "res = " << res << std::endl;

    return 0;
}
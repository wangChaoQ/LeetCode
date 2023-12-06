/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    main.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-12-06 10:39:38
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
    int input = atoi(argv[1]);
    
    std::cout << "input = " << input << std::endl;

    bool isnt = isPalindrome(input);

    std::cout << "isnt = " << isnt << std::endl;

    return 0;
}
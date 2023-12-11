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

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> boards;

    for(int i = 1; i < argc; i++)
    {
        // printf("atoi(argv[i]) :%d\n", atoi(argv[i]));
        boards.push_back(atoi(argv[i]));
    }

    printf("maxArea :%d\n", maxArea(boards));
}


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
    if(argc != 2)
    {
        printf("Wrong number of parameters!!!\n");
        exit(-1);
    }    
    int num = atoi(argv[1]);

    string Roman = intToRoman(num);

    cout << "Roman:" << Roman << endl;
}


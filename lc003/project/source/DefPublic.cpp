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

#include <sstream>
#include <stdio.h>
#include <string.h>
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

bool isExist(string s, char ch) {
    for(auto it = s.begin(); it != s.end(); it++)
    {
        if(*it == ch)
            return true;
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    // 确认一下收到的字符串是否正确
    int len = 1, count = 0;           //函数的返回值
    string substr;

    for(int i = 0, j = 0; i < s.length();)
    {
        if(!isExist(substr, s[i]))       // 不存在此字符
        {
            substr += s[i];
            count ++;
            i++;
        }
        else
        {
            cout << "substr = " << substr << endl;
            len = (len > count ? len : count);
            j ++;
            i = j;
            substr.clear();
            count = 0;
        }
    }
    cout << "substr = " << substr << endl;
    len = (len > count ? len : count);          //防止只有一个字符的情况,和遍历到最后的字符是最长的情况
    return len;
}
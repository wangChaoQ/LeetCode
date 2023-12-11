/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    DefPublic.h
 * @brief   
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-12-08 10:21:35
 ****************************************************************/
#ifndef _DEFPUBLIC_H__
#define _DEFPUBLIC_H__

#include <vector>
#include <string>

int printVector2(std::vector<std::vector<int>>& vector2);           // 打印二维数组
int maxArea(std::vector<int>& height);                              // 依次插不同高度木板，求最大容积
std::string intToRoman(int num);                                    // 整数转罗马数字
int romanToInt(std::string s);                                      // 罗马数字转整数


#endif // _DEFPUBLIC_H__
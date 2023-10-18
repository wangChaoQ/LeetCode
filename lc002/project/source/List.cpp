/****************************************************************
 * @copyright Copyright (c) 2023
 *            All rights reserved.
*****************************************************************
 * @file    List.cpp
 * @brief   null
 * @author  chaoqun.wang
 * @version 0.0.1
 * @date    2023-10-17 19:28:03
 ****************************************************************/
#include <iostream>
#include "List.h"

using namespace std;

void List::Insert(vector<int> nums)
{
    struct ListNode* newNode = NULL;
    for(int i = 0; i < nums.size(); i++)
    {
        newNode = new ListNode(nums[i], Head);
        Head = newNode;
    }
}
void List::Print()
{
    struct ListNode* senTry = NULL;
    senTry = Head;
    while(senTry)
    {
        cout << senTry->val ;
        senTry = senTry->next;
        if(senTry)
            cout << " , ";
    }
    cout << endl;
}
void List::Addition(List* l1, List* l2, List& result)
{
    if(l1 == NULL)
    {
        result.Head = l2->Head;
        return;
    }
    if(l2 == NULL)
    {
        result.Head = l1->Head;
        return;
    }

    int carry = 0, digit = 0;
    ListNode* ptr1 = l1->Head, *ptr2 = l2->Head;
    struct ListNode* newNode;
    while(ptr1 || ptr2)
    {
        if(ptr1 && ptr2)
        {
            digit = (ptr1->val + ptr2->val + carry) % 10;
            carry = (ptr1->val + ptr2->val + carry) / 10;
            newNode = new ListNode(digit);
            static bool isHead = true;
            if (isHead)
            {
                result.Head = newNode;
                result.Tail = newNode;
                isHead = false;
            }

            result.Tail->next = newNode;
            result.Tail = newNode;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1 == NULL)
        {
            digit = (ptr2->val + carry) % 10;
            carry = (ptr2->val + carry) / 10;
            newNode = new ListNode(digit);
            result.Tail->next = newNode;
            result.Tail = newNode;

            ptr2 = ptr2->next;
        }
        else if(ptr2 == NULL)
        {
            digit = (ptr1->val + carry) % 10;
            carry = (ptr1->val + carry) / 10;
            newNode = new ListNode(digit);
            result.Tail->next = newNode;
            result.Tail = newNode;

            ptr1 = ptr1->next;
            
        }
    }

    if(carry != 0)
    {
        newNode = new ListNode(carry);
        result.Tail->next = newNode;
        result.Tail = newNode;
    }
}
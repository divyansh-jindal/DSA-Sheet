// https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{
    if (arr.size() == 1)
        return;
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    };
    if (j == -1)
        return;
    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}
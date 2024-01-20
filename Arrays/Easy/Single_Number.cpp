// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        x ^= nums[i];
    }
    return x;
}
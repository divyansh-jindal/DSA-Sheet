// https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int total = ((n + 1) * (n)) / 2;
    for (int i = 0; i < n; i++)
    {
        total = total - nums[i];
    }
    return total;
}
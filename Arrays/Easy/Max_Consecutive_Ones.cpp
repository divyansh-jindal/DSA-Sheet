// https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ct = 0, maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            ct++;
            maxi = max(ct, maxi);
        }
        else
            ct = 0;
    }
    return maxi;
}
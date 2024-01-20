// https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(sum, maxi);

        if (sum < 0)
            sum = 0;
    }
    return maxi;
}
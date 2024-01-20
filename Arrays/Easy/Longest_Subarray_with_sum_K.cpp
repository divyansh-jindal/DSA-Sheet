// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &nums, int k)
{
    // Write your code here
    map<int, int> mpp;
    int mxlen = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            mxlen = max(mxlen, i + 1);
        int rem = sum - k;
        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem];
            mxlen = max(len, mxlen);
        }
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    return mxlen;
}
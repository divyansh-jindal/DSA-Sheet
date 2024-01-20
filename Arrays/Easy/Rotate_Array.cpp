// https://leetcode.com/problems/rotate-array/description/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.begin(), nums.end());
}
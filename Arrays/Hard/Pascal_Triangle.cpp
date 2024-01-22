// https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int n)
{
    vector<int> row;
    int ans = 1;
    row.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans *= (n - i);
        ans /= i;
        row.push_back(ans);
    }
    return row;
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        ans.push_back(generateRow(i + 1));
    }
    return ans;
}
// https://www.codingninjas.com/studio/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
    // Write your code here.
    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }
    return ans;
}
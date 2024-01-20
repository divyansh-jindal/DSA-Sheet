// https://www.codingninjas.com/studio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else
        {
            if (b[j] < a[i])
            {
                if (ans.size() == 0 || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            }
        }
    }
    while (j < n2)
    {
        if (ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }
    while (i < n1)
    {
        if (ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }
    return ans;
}
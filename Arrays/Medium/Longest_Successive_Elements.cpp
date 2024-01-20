// https://www.codingninjas.com/studio/problems/longest-successive-elements_6811740?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    int maxi = INT_MIN;
    int ct = 0;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            ct = 1;
            int x = it;

            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                ct++;
            }
            maxi = max(maxi, ct);
        }
    }

    return maxi;
}
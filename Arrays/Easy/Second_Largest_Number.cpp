// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

int getLargest(vector<int> a, int n)
{
    int lar = a[0];
    int small = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > lar)
        {
            small = lar;
            lar = a[i];
        }
        else if (a[i] < lar and a[i] > small)
        {
            small = a[i];
        }
    }
    return small;
}
int getSmallest(vector<int> a, int n)
{
    int small = a[0];
    int ssmall = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < small)
        {
            ssmall = small;
            small = a[i];
        }
        else if (a[i] > small and a[i] < ssmall)
        {
            ssmall = a[i];
        }
    }
    return ssmall;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    int sLargest = getLargest(a, n);
    int sSmallest = getSmallest(a, n);

    return {sLargest, sSmallest};
}

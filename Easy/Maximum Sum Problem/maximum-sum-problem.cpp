//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
         int fun(int i, vector<int> &dp) {
            if(i==0 || (i/2 + i/3 + i/4) < i) return i;
            if(dp[i]!=-1) return dp[i];
            
            return dp[i]= fun(i/2, dp)+fun(i/3, dp)+fun(i/4, dp);
        }
        
        int maxSum(int n) {
            vector<int> dp(n+1, -1);
            return fun(n, dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
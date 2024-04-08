//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long
class Solution{
    public:
    int dp[1002][1002][2];
    ll f( int i , int j , int canTake ,int arr[])
    {
        if ( i>j) return 0;
        if ( dp[i][j][canTake]!=-1) return dp[i][j][canTake];
        ll sum = 0 , notake = 0;
        if(canTake)
        {
            sum = max(arr[i]+f(i+1,j,0,arr),arr[j]+f(i,j-1,0,arr));
        }
        else sum = min(f(i+1,j,1,arr),f(i,j-1,1,arr));
        return dp[i][j][canTake] = sum ;
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,1,arr);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
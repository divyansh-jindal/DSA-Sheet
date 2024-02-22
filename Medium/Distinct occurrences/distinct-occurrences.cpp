//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    vector<vector<int>>dp;
    int n,m;
    int mod=(int)1e9+7;
    int solve(string &s,string &t,int i,int j)
    {
        if(j==m) return 1;
        if(i==n) return 0;
        
        int &ans= dp[i][j];
        if(ans!=-1) return ans;
        
        ans=0;
        ans+= solve(s,t,i+1,j);
        ans= ans%mod;
      if(s[i]==t[j])
        {
            ans= ans+ solve(s,t,i+1,j+1);
            ans= ans%mod;
        }
        return ans;
         }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      n=s.length();
      m= t.length();
      dp.resize(n,vector<int>(m,-1));
      return solve(s,t,0,0);
      
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
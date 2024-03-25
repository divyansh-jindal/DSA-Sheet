//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector <string> ans;
    
    void solve(string str, int n ,int i, int one, int zero)
    {
        if(zero > one) return;
        if(i == n)
        {
            ans.push_back(str);
            return ;
        }
        solve(str + "1", n, i+1, one+1, zero);
        solve(str + "0", n, i+1, one, zero+1);
    }
    
    vector<string> NBitBinary(int n)
    {
        solve("1", n, 1, 1, 0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            
            int n = price.size();
            
            // buy -> 0
            // sell -> 1
            vector<vector<int>>curr(3,vector<int>(3,0)) , prev(3,vector<int>(3,0));
            
            for(int i = n-1; i >= 0; i--)
            {
                for(int ops = 1; ops >= 0; ops--)
                {
                    for(int k = 1; k >= 0; k--)
                    {
                        if(ops == 0){
                
                             curr[ops][k] = max(prev[0][k] + 0ll, -price[i] + 0ll + prev[1][k]);
                        }
                        
                        else{

                             curr[ops][k] = max(prev[1][k] + 0ll, price[i] + 0ll + prev[0][k+1]);
                        }
                    }
                }
                
                prev = curr;
            }
            
            return prev[0][0];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
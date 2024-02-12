//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        int MOD = 1e9 + 7;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int s = (i*(i-1))/2 + 1;
            long long int sub_ans = 1;
            for(int j = s; j < s+i; j++)
                sub_ans = ((sub_ans % MOD) * (j % MOD)) % MOD;
            ans = (ans%MOD + sub_ans%MOD);
        }
        return ans % MOD;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
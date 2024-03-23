//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution {
public:
    vector<int> Series(int n) {
        vector<int> res;
        int a = 0, b = 1;
        
        res.push_back(a);
        res.push_back(b);
        
        for(int i = 2; i <= n; i++) {
            int c = (a + b) % mod;
            res.push_back(c);
            
            a = b;
            b = c;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        vector<int> d(r+1, 0);
        d[0] = n;
        for(int i = 1; i <= r; i++)
            d[i] = d[i-1]/2;
        // this is the root element which start generation
        char root = s[d[r]];
        while(r--) {
            if(root == '0') {
                if(d[r]&1) root = '1';
            } else {
                if(d[r]&1) root = '0';
            }
        }
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
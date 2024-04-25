//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid(int i,int j,int n,int m){
      if(i-1>=0 and i+1<n and j-1>=0 and j+1<m) return true;
      return false;
  }
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int maxi=INT_MIN;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isvalid(i,j,n,m)){
                    int sum = mat[i][j]+mat[i-1][j]+mat[i-1][j-1]+mat[i-1][j+1]
                                +mat[i+1][j]+mat[i+1][j+1]+mat[i+1][j-1];
                    maxi=max(maxi,sum);
                }
            }
        }
        return maxi==INT_MIN?-1:maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends
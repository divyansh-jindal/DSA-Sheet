//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        int dr[4][4]={{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0 , i = 0 , j = 0;
        while(1)
        {
            if(mat[i][j]) mat[i][j]=0,d = (d+1)%4;
            i += dr[d][0];
            j += dr[d][1];
            if(i>=n || j>=m || i<0 || j<0 ) return {i-dr[d][0],j-dr[d][1]};
        }
        return {0,0}; // this will never be executed 
        // it's just to avoid compiler error ...
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
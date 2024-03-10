//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(grid[0][j]) {
                vis[0][j]=1;
                q.push({0,j});
            }
            
            // last row 
            if(grid[n-1][j]) {
                vis[n-1][j]=1;
                q.push({n-1,j}); 
            }
        }
        
        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(grid[i][0]) {
                vis[i][0]=1;
                q.push({i,0});
            }
            
            // last column
            if(grid[i][m-1]) {
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc] and !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] and !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
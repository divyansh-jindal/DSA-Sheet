//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs (int row,int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>> &shape,int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        shape.push_back({row-row0,col-col0});
        
        int dr[]={0,1,0,-1};
        int dc[]={-1,0,1,0};
        
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            
            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc])
                dfs(nr,nc,grid,vis,shape, row0,col0);
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set <vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]){
                    vector<pair<int,int>> shape;
                    dfs(i,j,grid,vis,shape, i,j);
                    st.insert(shape);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
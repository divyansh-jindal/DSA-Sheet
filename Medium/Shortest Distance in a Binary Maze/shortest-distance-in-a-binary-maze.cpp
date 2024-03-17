//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        dist[source.first][source.second]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();
            
            if(row==destination.first and col==destination.second) return dis;
            
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and dis+1<dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
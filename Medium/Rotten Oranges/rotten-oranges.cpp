//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
       
        queue<pair<pair<int,int>,int>> q;
        int max_t=0;
        int n=grid.size();
        int m= grid[0].size();
        int mat[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    mat[i][j]=2;
                    q.push({{i,j},0});
                }
                else mat[i][j]=0;
            }
        }
        
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            
            for(int i=0;i<4;i++){
                
                    int nr = row+dr[i];
                    int nc = col+dc[i];
                    
                    if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and mat[nr][nc]!=2){
                        mat[nr][nc]=2;
                        q.push({{nr,nc},t+1});
                    }
                
            }
             max_t = max(t,max_t);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=2 and grid[i][j]==1){
                    return -1;
                }
            }
        }
        return max_t;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
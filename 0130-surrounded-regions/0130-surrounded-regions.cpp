class Solution {
public:
    void dfs(int r,int c, vector<vector<int>> &vis, vector<vector<char>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        
        vis[r][c]=1;
        
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            
            if(nr>=0 and nr<n and nc>=0 and nc < m and !vis[nr][nc] and mat[nr][nc]=='O'){
                dfs(nr,nc,vis,mat);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
                dfs(0,i,vis,mat);
            }
        }
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='O'){
                dfs(n-1,i,vis,mat);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                dfs(i,0,vis,mat);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat);
            }
        }
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and mat[i][j]=='O') mat[i][j]='X';
            }
        }

    }
};
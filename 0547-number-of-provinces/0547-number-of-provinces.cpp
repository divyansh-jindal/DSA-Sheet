class Solution {
public:
    void dfs(int node,vector<bool> &vis, vector<int> adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int r= isConnected.size();
        vector<bool> vis(r,0);
        vector<int> adj[r+1];

        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<r;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;

    }
};
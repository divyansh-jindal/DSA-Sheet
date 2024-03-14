//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node, stack<int>&st, int vis[], vector<pair<int,int>> adj[]){
         vis[node]=1;
         
         for(auto it:adj[node]){
             if(!vis[it.first]){
                 dfs(it.first,st,vis,adj);
             }
         }
         st.push(node);
     } 
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        int n=edges.size();
        int m=edges[0].size();
        
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        int vis[N]={0};
        stack<int> st;
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        
        vector<int> dist(N,1e8);
        dist[0]=0;
        
        while(!st.empty()){
            int node=st.top();
            int nodeDist=dist[node];
            st.pop();
            
            for(auto it:adj[node]){
                int el=it.first;
                int dis=it.second;
                
                dist[el]=min(nodeDist+dis,dist[el]);
            }
        }
        
        for(int i=0;i<N;i++)
        if(dist[i]>=1e8)
        dist[i]=-1;
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
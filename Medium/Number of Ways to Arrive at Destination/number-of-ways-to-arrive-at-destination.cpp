//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> ways(n,0);
        ways[0]=1;
        vector<long> dist(n,1e18);
        dist[0]=0;
        int mod=(int)(1e9 + 7);
        pq.push({0,0});
        
        while(!pq.empty()){
            int node=pq.top().second;
            long dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    ways[it.first]=ways[node]%mod;
                    pq.push({dist[it.first],it.first});
                }
                else if(dis+it.second==dist[it.first]) ways[it.first]=(ways[it.first]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
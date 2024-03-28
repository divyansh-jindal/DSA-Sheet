//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
typedef pair<int,int> pi;
class Solution {
    public:
    void dijkstra(vector<pi>* adj,int node,vector<int>& v)
    {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,node});
        v[node]=0;
        while(!pq.empty())
        {
            int n=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto it:adj[n])
            {
                int distance=it.second+d;
                if(v[it.first]>distance)
                {
                    pq.push({distance,it.first});
                    v[it.first]=distance;
                }
            }
        }
    }
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        //adjacency list
        vector<pi> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //dijkstra algorithm
        int ans=1e9;
        int node=-1;
        for(int i=0;i<n;i++)
        {
            vector<int> minPath(n,1e9);
            dijkstra(adj,i,minPath);
            
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                if(minPath[j]<=distanceThreshold)
                cnt++;
            }
            
            if(cnt<ans)
            {
                ans=cnt;
                node=i;
            }
            else if(cnt==ans)
            node=max(node,i);
        }
        return node;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
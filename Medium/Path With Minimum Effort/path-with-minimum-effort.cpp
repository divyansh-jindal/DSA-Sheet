//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        
        pq.push({0,{0,0}});
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        
        while(!pq.empty()){
            // int node=pq.top();
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            int diff=pq.top().first;
            pq.pop();
            
            if(row==n-1 and col==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    int newEffort = max(abs(heights[row][col] - heights[nr][nc]), diff);

                    if (newEffort < dist[nr][nc])
                    {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
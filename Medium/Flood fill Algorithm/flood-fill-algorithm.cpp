//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr, int sc, int newColor){
        int iniColor=image[sr][sc];
        int n= image.size();
        int m= image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and image[nr][nc]==iniColor){
                    image[nr][nc]=newColor;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n= image.size();
        int m= image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        bfs(image,vis,sr,sc,newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
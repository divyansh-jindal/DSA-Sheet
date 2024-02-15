//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n = paths.size();
	    int m = paths[0].size();
	    vector<int>v(n, 0);
	    
	    for(int i = 0 ; i < n ; i++) {
	        for(int j = 0 ; j < m ; j++) {
	            if(paths[i][j] == 1)
	                v[i]++;
	        }
	    }
	    
	    int flag = 1;
	    for(int i = 0 ; i < n ; i++) {
	        if(v[i] % 2 != 0) 
	           flag = 0;
	    }
	    return flag;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
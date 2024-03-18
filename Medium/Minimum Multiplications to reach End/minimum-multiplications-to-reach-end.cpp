//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        int n=arr.size();
        int mod=100000;
        vector<int> dist(100000,1e9);
        dist[start]=0;
        queue<pair<int,int>> q;
        q.push({0,start});
        
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto it:arr){
                int newNode=(node*it)%mod;
                
                if(steps+1<dist[newNode]){
                    dist[newNode]=steps+1;
                    if (newNode == end)
                        return steps + 1;
                    q.push({steps+1,newNode});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
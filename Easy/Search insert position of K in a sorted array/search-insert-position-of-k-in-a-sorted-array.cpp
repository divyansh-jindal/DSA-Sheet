//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int low =0;
        int high = N-1;
        int ind=INT_MIN;
        
        if(Arr[0]>k) return 0;

        if(Arr[N-1]<k) return N;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(Arr[mid]==k) return mid;
            else if(Arr[mid]>k){
                ind = mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ind;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
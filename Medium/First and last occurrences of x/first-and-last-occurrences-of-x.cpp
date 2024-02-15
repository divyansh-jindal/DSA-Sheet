//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int first(int arr[], int n , int x){
        int low =0;
        int high = n-1;
        int ans =-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]==x){
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]>x){
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int second(int arr[], int n , int x){
        int low =0;
        int high = n-1;
        int ans =-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]==x){
                ans=mid;
                low=mid+1;
            }
            else if(arr[mid]>x){
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int ans = first(arr,n,x);
       if (ans==-1)return {-1,-1};
       return {ans,second(arr,n,x)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
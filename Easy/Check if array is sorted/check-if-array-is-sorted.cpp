//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool helper(int arr[],int l,int r,int n){
      if(l>r) return true;
      int mid = (l+r)/2;
      if((mid-1)>=0 && arr[mid-1]>arr[mid]){
          return false;
      }
      if(mid+1<n && arr[mid+1]<arr[mid]){
          return false;
      }
      return helper(arr,l,mid-1,n) && helper(arr,mid+1,r,n);
  }
  
    bool arraySortedOrNot(int arr[], int n) {
        return helper(arr,0,n-1,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
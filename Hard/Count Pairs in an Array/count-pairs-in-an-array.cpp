//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int comparecount(int arr[],int l,int mid,int r){
    int n1=(mid-l+1),n2=(r-mid);
    vector<int> left(n1),right(n2);
    int i=0,j=0,k,res=0;
    while(i<n1){
        left[i]=arr[l+i];
        i++;
    }
    while(j<n2){
        right[j]=arr[mid+1+j];
        j++;
    }
    i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[l+k]=left[i++];
             k++;
        }else{
            arr[l+k]=right[j++];
            res+=(n1-i);
             k++;
        }
    }
    while(i<n1) {
        arr[l+k]=left[i];
        i++;
         k++;
    }
    while(j<n2){
        arr[l+k]=right[j];
        j++;
        k++;
    }
    return res;
}
int findpair(int arr[],int l,int r){
    int res=0;
    if(l<r){
        int mid=l+(r-l)/2;
        res+=findpair(arr,l,mid);
        res+=findpair(arr,mid+1,r);
        res+=comparecount(arr,l,mid,r);
    }
    return res;
}


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here  
      
        for(int i=0;i<n;i++)
            arr[i]=(i*arr[i]);
        
        
        return findpair(arr,0,n-1);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends
class Solution {
public:
    int searchInsert(vector<int>& Arr, int k) {
        int N=Arr.size();
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
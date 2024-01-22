class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int ct=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            ct+=mpp[rem];
            mpp[sum]++;
        }
        return ct;
    }
};
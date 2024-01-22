class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = ((n+1)*(n))/2;
        for(int i=0; i<n; i++){
            total = total - nums[i];
        }
        return total;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(ct==0){
                ct++;
                el=nums[i];
            }
            else{
                if(nums[i]==el) ct++;
                else ct--;
            }
        }
        return el;
    }
};
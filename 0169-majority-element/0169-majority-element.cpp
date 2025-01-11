class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int m = nums.size()/2;
        sort(nums.begin(), nums.end());

        int c=1;
        int mj;

        for(int i=1;i<nums.size(); i++){
            // cout<<nums[i];
            if(nums[i]==nums[i-1]) c++;
            else c=1;
            if(c>m) mj=nums[i];
        }
        return mj;
    }
};
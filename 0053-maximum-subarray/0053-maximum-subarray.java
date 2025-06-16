class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==1) return nums[0];

        int max=Integer.MIN_VALUE;
        int sum=0;

        for(int j=0 ; j<nums.length ; j++){
            sum+=nums[j];
            max = sum<max ? max : sum;

            if(sum<0) sum=0;    
        }
        return max;
    }
}
import java.lang.*;

class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==1) return nums[0];

        int max=Integer.MIN_VALUE;
        int sum=0;
        int n=nums.length;

        for(int j=0 ; j<n ; j++){
            sum+=nums[j];
            max=Math.max(sum,max);

            if(sum<0){
                sum=0;
                continue;
            }
        }
        return max;
    }
}
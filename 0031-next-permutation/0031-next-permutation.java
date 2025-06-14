import java.util.*;

class Solution {
    
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }

    int breakPoint(int[] nums){
        int b=-1;
        for(int i=(nums.length)-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                b=i;
                break;
            }
        }
        return b;
    }
    public void nextPermutation(int[] nums) {
        int n =nums.length;
        int b=breakPoint(nums);
        
        if(b==-1) {
            reverse(nums,b+1,n-1);
            return;
        }

        for(int i=(nums.length)-1 ; i>b ; i--){
            if(nums[i] > nums[b]){
                int temp=nums[i];
                nums[i]=nums[b];
                nums[b]=temp;
                break;
            }
        }

        reverse(nums,b+1,n-1);
        System.out.println(b);
    }
}
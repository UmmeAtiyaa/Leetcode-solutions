import java.util.*;

class Solution {

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
        int b=breakPoint(nums);
        
        if(b==-1) {
            Arrays.sort(nums);
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

        Arrays.sort(nums, b+1, nums.length);
        System.out.println(b);
    }
}
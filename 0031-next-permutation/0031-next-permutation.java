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
        Arrays.sort(nums, b+1,nums.length);

        int temp; 

        if(b==-1) Arrays.sort(nums);
        
        else{
            temp=nums[b];
            nums[b]=nums[b+1];
            nums[b+1]=temp;
        }

        // Arrays.sort(nums, b+1, nums.length-1);
        System.out.println(b);
    }
}
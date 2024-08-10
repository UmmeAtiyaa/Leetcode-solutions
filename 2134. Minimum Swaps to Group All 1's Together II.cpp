class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(); 
        int k = count(nums.begin(), nums.end(), 1); 
        int countOne = 0;
        int maxOne = 0;

        for (int i = 0; i < n * 2; ++i) {
            if (i >= k && nums[(i - k) % n]) {
                --countOne; 
            }
            if (nums[i % n]) {
                ++countOne; 
            }
            maxOne = max(maxOne, countOne); 
        }

        return k - maxOne;
    }
};

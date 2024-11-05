
class Solution {
public:
    int countPairsWithDistanceLessThanOrEqualTo(std::vector<int>& nums, int mid) {
        int count = 0;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }
        return count;
    }

    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countPairsWithDistanceLessThanOrEqualTo(nums, mid);
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

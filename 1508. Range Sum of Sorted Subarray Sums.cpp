#include <numeric> 
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1'000'000'007;
        vector<int> arr;
        
        for(int i=0; i<n ; i++){
            int elem=nums[i];
            arr.push_back(elem);

            for(int j=i+1 ; j<n ; j++){
                elem = elem + nums[j];
                arr.push_back(elem);
            }
        }
        sort(arr.begin(), arr.end());

        int64_t result = 0;
        for (int i = left - 1; i < right; ++i) {
            result += arr[i];
            result %= MOD; 
        }
        return result;
    }
};

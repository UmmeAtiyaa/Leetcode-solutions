class Solution {
public:

    void solve(vector<int>& candidates, int target, vector<int>& current, int idx, vector<vector<int>>& result){
        if(target < 0){
            return;
        }
        if(target==0){
            result.push_back(current);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            current.push_back(candidates[i]);
            solve(candidates, target-candidates[i], current, i+1, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, current, 0, result);

        return result;
    }
};

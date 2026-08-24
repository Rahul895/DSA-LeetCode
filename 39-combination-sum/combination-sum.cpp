class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        dfs(candidates, target, 0, current, ans);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int i,
             vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        current.push_back(candidates[i]);

        dfs(candidates, target - candidates[i], i, current, ans);

        current.pop_back();

        dfs(candidates, target, i + 1, current, ans);
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> next = intervals[i];

            if (next[0] <= current[1]) {
                current[1] = max(current[1], next[1]);
            } else {
                ans.push_back(current);
                current = next;
            }
        }

        ans.push_back(current);

        return ans;
    }
};
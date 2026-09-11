class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int gap = max(1, (mx - mn) / (n - 1));

        vector<int> bucketMin(n, INT_MAX);
        vector<int> bucketMax(n, INT_MIN);
        vector<bool> used(n, false);

        for (int x : nums) {
            int i = min(n - 1, (x - mn) / gap);

            bucketMin[i] = min(bucketMin[i], x);
            bucketMax[i] = max(bucketMax[i], x);
            used[i] = true;
        }

        int ans = 0;
        int prev = mn;

        for (int i = 0; i < n; i++) {
            if (!used[i]) continue;

            ans = max(ans, bucketMin[i] - prev);
            prev = bucketMax[i];
        }

        return ans;
    }
};
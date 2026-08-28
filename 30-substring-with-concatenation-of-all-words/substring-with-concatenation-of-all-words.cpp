class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> need;

        for (string w : words)
            need[w]++;

        int len = words[0].size();
        int total = len * words.size();

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> have;

            for (int right = i; right + len <= s.size(); right += len) {
                string w = s.substr(right, len);

                if (!need.count(w)) {
                    have.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                have[w]++;
                count++;

                while (have[w] > need[w]) {
                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }

                if (count == words.size()) {
                    ans.push_back(left);

                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};
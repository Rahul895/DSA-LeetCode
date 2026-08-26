class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, ones = 0, len = INT_MAX;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') ones++;

            while (ones == k) {
                int currLen = right - left + 1;
                string cur = s.substr(left, currLen);

                if (currLen < len || (currLen == len && cur < ans)) {
                    len = currLen;
                    ans = cur;
                }

                if (s[left] == '1') ones--;
                left++;
            }
        }

        return ans;
    }
};
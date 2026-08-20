class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string curr = "";
        
        backtrack(digits, 0, curr, res, pad);
        return res;
    }

private:
    void backtrack(const string& digits, int i, string& curr, vector<string>& res, const vector<string>& pad) {
        if (i == digits.length()) {
            res.push_back(curr);
            return;
        }
        for (char c : pad[digits[i] - '0']) {
            curr.push_back(c);
            backtrack(digits, i + 1, curr, res, pad);
            curr.pop_back();
        }
    }
};
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        for (int i = 0; i < words.size();) {
            int j = i;
            int len = 0;

            // Find how many words can fit
            while (j < words.size() &&
                   len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int spaces = maxWidth - len;
            int gaps = j - i - 1;

            string line;

            // Last line OR only one word
            if (j == words.size() || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += " ";
                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int each = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += string(each + (k - i < extra), ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
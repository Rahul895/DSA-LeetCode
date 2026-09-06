class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string dir;

        stringstream ss(path);

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".")
                continue;

            if (dir == "..") {
                if (!st.empty())
                    st.pop_back();
            }
            else {
                st.push_back(dir);
            }
        }

        string ans;
        for (string s : st)
            ans += "/" + s;

        return ans.empty() ? "/" : ans;
    }
};
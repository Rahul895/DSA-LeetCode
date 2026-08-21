class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, i, j, 0))
                    return true;

        return false;
    }

    bool dfs(vector<vector<char>>& b, string& w, int r, int c, int i) {
        if (i == w.size()) return true;

        if (r < 0 || c < 0 || r >= b.size() || c >= b[0].size() ||
            b[r][c] != w[i])
            return false;

        char x = b[r][c];
        b[r][c] = '#';

        bool ans = dfs(b,w,r+1,c,i+1) ||
                   dfs(b,w,r-1,c,i+1) ||
                   dfs(b,w,r,c+1,i+1) ||
                   dfs(b,w,r,c-1,i+1);

        b[r][c] = x;
        return ans;
    }
};
class Solution {
public:
    vector<int> memo;

    bool dfs(int cur, string& s, vector<string>& wordDict) {
        if (cur == s.size()) return true;
        if (memo[cur] != -1) {
            return (memo[cur] == 1);
        }
        for (string& word : wordDict) {
            // let's match the word 
            int m = word.size();
            int j = cur;
            for (int i = 0; i < m; i++) {
                if (word[i] == s[j]) j++;
                else break;
            }
            if (j == cur + m) {
                // word found
                if (dfs(j, s, wordDict)) {
                    memo[cur] = 1;
                    return true;
                }
            }
        }
        // any word not match
        memo[cur] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);
        bool ans = dfs(0, s, wordDict);
        return ans;
    }
};

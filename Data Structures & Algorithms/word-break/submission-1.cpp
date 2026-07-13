class Solution {
public:
    bool match(int cur, string& wrd, string& s) {
        // implement it
        int m = wrd.size();
        int j = cur - m + 1;
        for (int i = 0; i < m; i++) {
            if (wrd[i] != s[j++]) return false;
        }
        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            for (string& wrd : wordDict) {
                if ( i >= wrd.size() - 1 &&
                    (i == wrd.size() - 1 || dp[i - wrd.size()] == 1) 
                    ) {
                    if (match(i, wrd, s)) {
                        dp[i] = 1;
                        break;
                    };
                }
            }
        }
        for (int i : dp) cout << i << " ";
        cout << endl;
        return (dp.back() == 1);
    }
};
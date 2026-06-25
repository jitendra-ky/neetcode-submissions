class Solution {
public:
    vector<vector<int>> memo;
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<int>(n, -11));
        for (int i = 0; i < n; i++) {
            memo[i][i] = nums[i];
        }
        int maxP = nums[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                maxP = max(maxP, product(i, j, nums));
            }
        }
        return maxP;
    }

    int product(int l, int r, const vector<int>& nums) {
        if (memo[l][r] != -11) return memo[l][r];
        int p = nums[l] * product(l + 1, r, nums);
        memo[l][r] = p;
        return p;
    }
};
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sm = accumulate(nums.begin(), nums.end(), 0);

        if (sm % 2 != 0)
            return false;

        int target = sm / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;

                if (j >= nums[i])
                    take = dp[i - 1][j - nums[i]];

                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};
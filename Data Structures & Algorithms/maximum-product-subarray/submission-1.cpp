class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = nums[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                maxP = max(maxP, product(i, j, nums));
            }
        }
        return maxP;
    }

    int product(int l, int r, const vector<int>& nums) {
        if (l == r) return nums[l];
        return nums[l] * product(l + 1, r, nums);
    }
};
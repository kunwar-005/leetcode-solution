class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {

            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;
            int s = -1 * nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == s) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < n and nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (k >= 0 and nums[k]==nums[k + 1]) {
                        k--;
                    }

                } else if (sum < s) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};
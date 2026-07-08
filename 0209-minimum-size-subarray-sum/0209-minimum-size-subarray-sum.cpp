class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int mini = INT_MAX;
        int sum = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {

            sum += nums[j];

            while (sum >= target) {
                mini = min(mini, j - i + 1);

                sum -= nums[i];
                i++;
            }
        }

        return (mini == INT_MAX) ? 0 : mini;
    }
};
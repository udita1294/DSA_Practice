class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>prev_idx(n,-1);
        int last_choosen_idx = 0;
        int maxl = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev_idx[i] = j;
                    }
                    if(dp[i] > maxl){
                        maxl = dp[i];
                        last_choosen_idx = i;
                    }
                }
            }
        }
        vector<int>result;
        while(last_choosen_idx != -1){
            result.push_back(nums[last_choosen_idx]);
            last_choosen_idx = prev_idx[last_choosen_idx];
        }
        return result;
    }
};
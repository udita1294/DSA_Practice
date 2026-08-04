class Solution {
public:
    int t[2501][2502];
    int solve(vector<int>& nums,int i,int prev){
        if(i >= nums.size()) return 0;
        if(t[i][prev+1] != -1) return t[i][prev+1];

        int take = 0 ;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + solve(nums,i+1,i);
        }
        int skip = solve(nums,i+1,prev);

        return t[i][prev+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};
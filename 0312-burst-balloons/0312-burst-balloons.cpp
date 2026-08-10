class Solution {
public:
    int t[301][301];
    int solve(int i,int j,vector<int>& nums){
        if(i > j) return 0;
        if(t[i][j] != -1)return t[i][j];
        int max_ans = INT_MIN;
        for(int k=i;k<=j;k++){
            int ans = 0;
            ans = nums[i-1]*nums[k]*nums[j+1];
            ans += solve(i,k-1,nums);
            ans += solve(k+1,j,nums);
            max_ans = max(max_ans,ans);
        }
        return t[i][j] = max_ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(1,n,nums);
    }
};
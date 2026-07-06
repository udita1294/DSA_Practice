class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftprod = 1;
        int rightprod = 1;
        vector<int>ans(n,1);

        for(int i=0;i<n;i++){
            ans[i] = leftprod;
            leftprod *= nums[i];
        }

        for(int i=n-1;i>=0;i--){
            ans[i] *= rightprod;
            rightprod *= nums[i];
        }
        return ans;
    }
};
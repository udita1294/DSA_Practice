class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long product1 = 1;
        long long product2 = 1;

        int n = nums.size();
        sort(nums.begin(),nums.end());

        product1 = nums[n-3]*nums[n-2]*nums[n-1];
        product2 = nums[0]*nums[1]*nums[n-1];

        return max(product1,product2);
    }
};
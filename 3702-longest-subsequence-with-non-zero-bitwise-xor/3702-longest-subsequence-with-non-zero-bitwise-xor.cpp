class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int resultXOR = 0;
        int zeros = 0;
        for(int &num : nums){
            resultXOR ^= num;
            if(num == 0) zeros++;
        }
        if(resultXOR != 0) return n;
        if(zeros == n) return 0;
        
        return n-1;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long totalXor = 0;
        for(int &num : nums){
            totalXor ^= num;
        }
        long long mask = (totalXor) & (-totalXor);
        int groupA = 0;
        int groupB = 0;

        for(int &num : nums){
            if((num & mask) != 0){
                groupA ^= num;
            }else{
                groupB ^= num;
            }
        }
        return {groupA,groupB};
    }
};
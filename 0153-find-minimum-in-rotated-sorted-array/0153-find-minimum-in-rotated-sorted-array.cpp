class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = nums[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[0] > nums[mid]){
                ans = nums[mid];
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
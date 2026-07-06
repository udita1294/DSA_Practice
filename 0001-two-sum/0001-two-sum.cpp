class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(),arr.end());
        int i = 0 ;
        int j = n-1;
        vector<int>ans;

        while(i < j){
            if(arr[i].first + arr[j].first == target){
                ans.push_back(arr[i].second);
                ans.push_back(arr[j].second);
            }if(arr[i].first + arr[j].first < target){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }

};
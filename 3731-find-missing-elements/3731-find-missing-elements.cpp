class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums.size();
        int index = 0;
        for(int x : nums) mp[x]++;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());

        for(int i = mini;i <= maxi;i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
                index++;
            }
        }
        return ans;
    }
};
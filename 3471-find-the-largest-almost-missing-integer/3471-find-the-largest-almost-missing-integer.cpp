class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int l = 0; l + k <= n; l++){
            int i = l;
            int r = l + k - 1;
            unordered_set<int> st;
            while(i <= r){
                st.insert(nums[i]);
                i++;
            }
            for(auto x : st){
                mp[x]++;
            }
        }
        int ans = -1;
        for(auto &p : mp){
            if(p.second == 1){
                ans = max(ans, p.first);
            }
        }
        return ans;
    }
};
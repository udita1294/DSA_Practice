class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>g;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            int gc = gcd(maxi,nums[i]);
            g.push_back(gc);
        }

        sort(g.begin(),g.end());
        long long sum = 0;
        for(int i=0 , j = n-1 ; i < n/2 ;i++,j--){
            sum += gcd(g[i],g[j]);
        }
        return sum;

    }
};
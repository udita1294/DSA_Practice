class Solution {
public:
    int t[105][105];
    int solve(int l,int r,vector<int>& cuts){
        if(l + 1 == r) return 0;
        if(t[l][r] != -1) return t[l][r];
        int cost = 0;
        int min_cost = INT_MAX;
        for(int i = l+1 ; i <= r-1; i++){
            cost = cuts[r] - cuts[l] + solve(l,i,cuts) + solve(i,r,cuts);
            min_cost = min(min_cost , cost);
        }
        return t[l][r] = min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(t,-1,sizeof(t));
        int z = cuts.size();
        vector<int>ans;
        ans.push_back(0);
        for(int i=0;i<z;i++){
            ans.push_back(cuts[i]);
        }
        ans.push_back(n);
        sort(ans.begin(),ans.end());
        int s = ans.size();
        return solve(0,s-1,ans);
    }
};
class Solution {
public:
    int t[1001][1001];
    int solve(vector<vector<int>>& pairs,int i,int prev){
        if(i >= pairs.size())return 0;
        if(t[i][prev+1] != -1) return t[i][prev+1];

        int take = 0;
        if(prev == -1 || pairs[prev][1] < pairs[i][0]){
            take = 1 + solve(pairs,i+1,i);
        }
        int skip = 0 + solve(pairs,i+1,prev);
        return t[i][prev+1] = max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        memset(t,-1,sizeof(t));
        sort(pairs.begin(),pairs.end());
        return solve(pairs,0,-1);
    }
};
class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty, int d,int index,int n){
        if(d == 1){
            return *max_element(jobDifficulty.begin() + index ,jobDifficulty.end());
        }
        if(t[index][d] != -1) return t[index][d];

        int maxD = jobDifficulty[index];
        int finalResult = INT_MAX;
        for(int i = index;i <= n-d; i++){
            maxD = max(maxD , jobDifficulty[i]);

            int result = maxD + solve(jobDifficulty,d-1,i+1,n);
            finalResult = min(finalResult,result);
        }
        return t[index][d] = finalResult;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        memset(t,-1,sizeof(t));
        if(n < d){
            return -1;
        }
        return solve(jobDifficulty,d,0,n);
    }
};
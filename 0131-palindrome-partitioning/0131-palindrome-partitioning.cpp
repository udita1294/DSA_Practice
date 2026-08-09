class Solution {
public:
    vector<vector<vector<vector<string>>>>dp;
    bool isPalindrome(string &s,int i,int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>>solve(string &s,int i,int j){
        if(i > j){
            return {{}};
        }
        if(!dp[i][j].empty()) {
            return dp[i][j];
        }
        vector<vector<string>>ans;
        for(int k=i;k<=j;k++){
            if(isPalindrome(s,i,k)){
                string curr = s.substr(i, k-i+1);
                vector<vector<string>>temp = solve(s,k+1,j);

                for(auto v : temp){
                    v.insert(v.begin(),curr);
                    ans.push_back(v);
                }
            }

        }
        return dp[i][j] = ans;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<vector<vector<string>>>(n));
        return solve(s,0,n-1);
    }
};
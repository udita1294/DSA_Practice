class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1)return s;
        string ans = "";

        for(int i=0;i<n/2;i++){
            ans += s[i];
        }
        sort(ans.begin(),ans.end());
        string rev = ans;
        reverse(rev.begin(),rev.end());
        
        if(n % 2 == 1){
            ans += s[n/2];
        }

        for(int i=0;i<n/2;i++){
            ans += rev[i];
        }
        return ans;
    }
};
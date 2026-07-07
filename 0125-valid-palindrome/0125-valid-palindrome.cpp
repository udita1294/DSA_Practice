class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                ans.push_back(tolower(s[i]));
            }
        }
        string rev = ans;
        reverse(rev.begin(),rev.end());
        if(ans == rev){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l=0;
        int r=0;
        int len = INT_MAX;
        int ones = 0;
        string result = "";
        while(r < n){
            if(s[r] == '1') ones++;
            while(ones > k || s[l] == '0'){
                if(s[l] == '1')ones--;
                l++;
            }
            if(ones == k){
                string temp = s.substr(l,r-l+1);
                if(result.empty() || result.size() > r-l+1 || (temp.size() == result.size() && temp < result)){
                    result = temp;
                }
            }
            r++;
        }
        return result;
    }
};
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans;
        int len = min(n,m);

        for(int i =0;i< len;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if(n > len){
            ans += word1.substr(len);
        }
        if(m > len){
            ans += word2.substr(len);
        }
        return ans;
    }
};
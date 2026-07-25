class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        string ans = "";
        unordered_map<string, int> mp;
        int length = 0;

        for (string x : words) {
            mp[x]++;
        }
        bool centreUsed = 0;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev) {
                if (mp[word] > 0 && mp[rev] > 0) {
                    mp[word]--;
                    mp[rev]--;
                    length += 4;
                }
            } else {
                if (mp[word] >= 2) {
                    mp[word] -= 2;
                    length += 4;
                } else if (mp[word] == 1 && !centreUsed) {
                    mp[word]--;
                    centreUsed = true;
                    length += 2;
                }
            }
        }
        return length;
    }
};
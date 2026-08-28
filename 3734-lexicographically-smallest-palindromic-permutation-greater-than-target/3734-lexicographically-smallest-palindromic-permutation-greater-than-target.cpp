class Solution {
public:
    string makePalindrome(string half, char mid) {
        string res = half;
        if (mid != '#')
            res += mid;
        for (int i = half.size() - 1; i >= 0; i--)
            res += half[i];
        return res;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        // Count characters
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        // Check whether a palindrome is possible
        int odd = 0;
        char mid = '#';
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }
        if (odd > 1)
            return "";
        // Characters available in the first half
        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;
        int m = n / 2;
        string ans = "";
        /*
            Try every position where our palindrome
            becomes greater than target.

            Positions before 'pos' are equal to target.
            At 'pos', choose the smallest character
            greater than target[pos].
        */
        for (int pos = 0; pos < m; pos++) {
            vector<int> rem = halfCnt;
            string half;
            bool possible = true;
            // Match target prefix
            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';
                if (rem[x] == 0) {
                    possible = false;
                    break;
                }
                half += target[i];
                rem[x]--;
            }
            if (!possible)
                continue;
            // Make the first different character larger
            for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;
                string h = half;
                h += char('a' + c);
                rem[c]--;
                // Fill remaining half with smallest characters
                for (int x = 0; x < 26; x++) {
                    h += string(rem[x], char('a' + x));
                }
                string pal = makePalindrome(h, mid);
                if (pal > target) {
                    if (ans.empty() || pal < ans)
                        ans = pal;
                }
                rem[c]++;
            }
        }
        /*
            Also check the palindrome whose first half
            is exactly equal to target's first half.

            The second half / middle may make it greater.
        */
        {
            vector<int> rem = halfCnt;
            string half;
            bool possible = true;
            for (int i = 0; i < m; i++) {
                int x = target[i] - 'a';
                if (rem[x] == 0) {
                    possible = false;
                    break;
                }
                half += target[i];
                rem[x]--;
            }
            if (possible) {
                string pal = makePalindrome(half, mid);
                if (pal > target) {
                    if (ans.empty() || pal < ans)
                        ans = pal;
                }
            }
        }
        return ans;
    }
};
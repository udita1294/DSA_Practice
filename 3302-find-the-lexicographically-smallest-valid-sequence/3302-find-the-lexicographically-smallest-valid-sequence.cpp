class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;

        bool used = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            else if (!used) {

                if (j == m - 1 || (suf[j + 1] != -1 && suf[j + 1] > i)) {
                    used = true;
                    ans.push_back(i);
                    j++;
                }
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};
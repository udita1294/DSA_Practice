class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())return false;
        vector<int>A(26,0);
        vector<int>B(26,0);

        for(int i=0;i<word1.size();i++){
            char ch = word1[i];
            A[ch-'a']++;
        }
        for(int i=0;i<word2.size();i++){
            char ch = word2[i];
            B[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            if(A[i] == 0 && B[i] != 0)return false;
            if(A[i] != 0 && B[i] == 0)return false; 
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        return (A == B);
    }
};
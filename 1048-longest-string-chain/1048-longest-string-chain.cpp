class Solution {
public:
    int t[1001][1001];
    bool predecessor(string& prev, string& curr){
        int M = prev.size();
        int N = curr.size();
        if(M >= N || N-M != 1) return false;
        int i = 0 , j = 0;
        while(i < M && j < N){
            if(prev[i] == curr[j]){
                i++;
            }j++;
        }
        return i == M ;
    }
    static bool wordLenSort(string& word1,string& word2){
        return word1.length() < word2.length();
    }
    int solve(vector<string>& words,int i,int prev){
        if(i >= words.size())return 0;
        if(t[i][prev+1] != -1) return t[i][prev+1];
        int take = 0;
        if(prev == -1 || predecessor(words[prev],words[i])){
            take = 1 + solve(words,i+1,i);
        }
        int skip = 0 + solve(words,i+1,prev);

        return t[i][prev+1] = max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        memset(t,-1,sizeof(t));
        sort(words.begin(),words.end(),wordLenSort);

        return solve(words,0,-1);
    }
};
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int maxScore = 0;
        int score = 0;
        int i=0, j = n-1;

        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                maxScore = max(maxScore,score);
                i++;
            }else if(score > 0){
                    power += tokens[j];
                    score--;
                    j--;
            }else{
                return maxScore;
            }
        }
        return maxScore;         
    }
};
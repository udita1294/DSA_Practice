class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if(n <= 2)return false;
        int countA = 0;
        int countB =0;
        for(int i=1;i<n-1;i++){
            if(colors[i] == colors[i-1] && colors[i] == colors[i+1] && colors[i] == 'A')countA++;
            if(colors[i] == colors[i-1] && colors[i] == colors[i+1] && colors[i] == 'B')countB++;
        }
        if(countB >= countA){
            return false;
        }
        return true;
    }
};
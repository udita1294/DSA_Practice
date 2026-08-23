class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0;
        int leftQnMark = 0;
        int rightSum = 0;
        int rightQnMark = 0;
        
        for(int i=0;i<n;i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftQnMark++;
                }else{
                    rightQnMark++;
                }  
            }else{
                if(i < n/2){
                    leftSum += num[i] - '0';
                }else{
                    rightSum += num[i] - '0';
                }
            }
        }

        int totalQnMarks = leftQnMark + rightQnMark;
        if(totalQnMarks % 2 != 0){
            return true;
        }

        int LEFT = 2 * leftSum + 9*leftQnMark;
        int RIGHT = 2 * rightSum + 9*rightQnMark;

        if(LEFT == RIGHT){
            return false;
        }

        return true;
    }
};
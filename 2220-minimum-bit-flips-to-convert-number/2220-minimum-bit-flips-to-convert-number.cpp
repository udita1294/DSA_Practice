class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        while(start !=0 || goal != 0){
            int rightMostBitA = (start & 1);
            int rightMostBitB =(goal & 1);

            if(rightMostBitA != rightMostBitB) flips++;

            start >>= 1;
            goal >>= 1;
        }
        return flips;
    }
};
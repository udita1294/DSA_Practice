class Solution {
public:
    int GCD(int n1,int n2){
        if(n2 == 0){
            return n1;
        }
        return GCD(n2, n1 % n2);
    }
    int gcdOfOddEvenSums(int n) {
        int sum1 = 0;
        int sum2 =0;
        int count = 0;
        int i1 = 1 ;
        int i2 = 2;
        while(count <= n){
            sum1 += i1;
            i1 += 2;
            sum2 += i2;
            i2 += 2;
            count++;
        }

        return GCD(sum1,sum2) - 1;
    }
};
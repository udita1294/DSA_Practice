class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        long long product = 1;
        int num = n;
        while(num){
            int ld = num % 10;
            sum += ld;
            product *= ld;
            num /= 10;
        }
        if(n % (sum + product) == 0 ){
            return true;
        }
        return false;
    }
};
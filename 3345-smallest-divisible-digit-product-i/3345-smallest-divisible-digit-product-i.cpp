class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; ;i++){
            long long product = 1;
            int num = i;
            while(num){
                int ld = num % 10;
                num = num / 10;
                product *= ld;
            }
            if(product % t == 0){
                return i;
                break;
            }
        }
    }
};
class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int len = s.size();

        sort(s.begin(),s.end());
        long long product = 1;

        char one = s[len-1];
        char two = s[len - 2];

        int num1 = one - '0';
        int num2 = two - '0';

        product = num1 * num2;

        return product;
    }
};
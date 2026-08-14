class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [](int &a, int& b){
            int countOnesA = __builtin_popcount(a);
            int countOnesB = __builtin_popcount(b);
            if(countOnesA == countOnesB){
                return a < b;
            }
            return countOnesA < countOnesB;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};
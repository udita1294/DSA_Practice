class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int ans = 1;
        for(char x : s){
            if(st.count(x)){
                ans++;
                st.clear();
            }
            st.insert(x);
        }
        return ans;
    }
};
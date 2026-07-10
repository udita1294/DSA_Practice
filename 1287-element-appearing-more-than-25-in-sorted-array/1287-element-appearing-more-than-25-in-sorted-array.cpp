class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>mp;
        int n = arr.size();
        for(int x : arr){
            mp[x]++;
        }


        for(auto p : mp){
            if(p.second * 4 > n){
                return p.first;
            }
        }
        return -1;
    }
};
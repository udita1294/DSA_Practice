class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>requiredRocks(n);

        for(int i=0;i<n;i++){
            int currently_rock = rocks[i];
            int capacity_rock = capacity[i];
            int needed = capacity_rock - currently_rock;
            requiredRocks[i] = needed;
        }
        sort(requiredRocks.begin(),requiredRocks.end());
        int count = 0;

        for(int i=0;i<n;i++){
            if(additionalRocks >= requiredRocks[i]){
                additionalRocks -= requiredRocks[i];
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};